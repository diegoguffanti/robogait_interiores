//C++ includes
#include <iostream>
#include <fstream>
#include <csignal>
using namespace std;
//Linux includes
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <tf2/LinearMath/Quaternion.h>
//ROS2 includes
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "std_msgs/msg/float32.hpp"
using namespace rclcpp;
using placeholders::_1;

int serial_port; //Descriptor UART
struct termios tty; //Configuraciones UART
float rx_buf[6], tx_buf[3]; //Buffers comunicacion


void end(int signum)
{ //Armado senal Ctrl+C
	cout << "Stopping the robot" << endl;	
	tx_buf[0] = 0.0; //Velocidad x requerida
	tx_buf[1] = 0.0; //Rotacion z requerida
	write(serial_port, tx_buf, 2 * sizeof(float));
	cout << "Communication ended" << endl;
	shutdown();
	exit(signum); 
}


class driver_controller : public Node
{
public:
	//Constructor del nodo
	driver_controller() : Node("driver_controller")
	{
		//Armado senal Ctrl+C
		signal(SIGINT, end);

		//Configuracion puerto COM
		serial_port = open("/dev/STMserie", O_RDWR);
		if(serial_port < 0) 
		{
			cout << "COM error. Check USB connection" << endl;
			exit(1);
		}
		if(tcgetattr(serial_port, &tty) != 0)
		{
			cout << "COM config error 1" << endl;
			exit(1);
		}
		//Parametros mas frecuentes
		cfsetispeed(&tty, B9600); //Baud rate entrada
		cfsetospeed(&tty, B9600); //Baud rate salida
		tty.c_cflag &= ~PARENB; //Sin bit de paridad
  		tty.c_cflag &= ~CSTOPB; //1 bit parada
		tty.c_cflag |= CS8; //8 bits por byte
		tty.c_cc[VTIME] = 10; //Timeout en decisegundos
		tty.c_cc[VMIN] = 0; //Numero de bytes esperados (0 es cualquiera)
		//Otros parametros
		tty.c_cflag &= ~CSIZE; // Clear all bits that set the data size 
		tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control (most common)
		tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)
		tty.c_lflag &= ~ICANON;
		tty.c_lflag &= ~ECHO; // Disable echo
		tty.c_lflag &= ~ECHOE; // Disable erasure
		tty.c_lflag &= ~ECHONL; // Disable new-line echo
		tty.c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT and SUSP
		tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
		tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes
		tty.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
		tty.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed
		//Guardar cambios
		if(tcsetattr(serial_port, TCSANOW, &tty) != 0)
		{
			cout << "COM config error 2" << endl;
			exit(1);
		}

		//Suscripcion a Twist
		subscription_ = this->create_subscription<geometry_msgs::msg::Twist>(
		      "/cmd_vel", 10, bind(&driver_controller::topic_callback, this, _1));
		//Publicacion a Odometry
		publisher_ = this->create_publisher<nav_msgs::msg::Odometry>("/wheel/odometry", 10);
		publisher_imu = this->create_publisher<sensor_msgs::msg::Imu>("/imu/data", 10);
		publisher_camera = this->create_publisher<std_msgs::msg::Float32>("camera_position", 10);
		subscription_camera = this->create_subscription<std_msgs::msg::Float32>("cmd_camera", 10, bind(&driver_controller::topic_callback_camera, this, _1));
		      
		//Inicialiacion thread principal
		pub = thread(&driver_controller::loop, this);
	}
private:
	//Funciones miembro
	
	
	
	void topic_callback(const geometry_msgs::msg::Twist::SharedPtr msg) const
	{ //Callback de suscripcion
		//Formacion mensaje saliente
		cout << "Arrived cmd_vel request" << endl;
		tx_buf[0] = msg->linear.x; //Velocidad x requerida
		tx_buf[1] = msg->angular.z; //Rotacion z requerida
		//tx_buf[2] = 1.5; //Angulo camara requerido
		//Envio mensaje UART
		write(serial_port, tx_buf, 3 * sizeof(float));
	}
	void topic_callback_camera(const std_msgs::msg::Float32::SharedPtr msg) 
	{ //Callback de suscripcion
		////Formacion mensaje saliente
		cout << "Arrived cmd_camera request" << endl;
		tx_buf[2] = msg->data; //Velocidad x requerida
		//Envio mensaje UART
		write(serial_port, tx_buf, 3 * sizeof(float));
	}
	void loop()
	{ //Bucle principal
		cout << "Starting communication" << endl;
		
		
		while (1)
		{
			//Recepcion mensaje UART
			read(serial_port, rx_buf, 9 * sizeof(float));
			
			/*rx_buf[0]=robot_x_pos;
    			rx_buf[1]=robot_y_pos;
		    	rx_buf[2]=robot_angular_pos;
		    	rx_buf[3]=robot_linear_vel;
		    	rx_buf[4]=0; //Reserved to split vel in x and y if necessary.
		    	rx_buf[5]=robot_angular_vel;
		    	rx_buf[6]=mag_y;
		    	rx_buf[7]=gyro_z;
		    	rx_buf[8]=accel_x;*/

			//Comprension mensaje entrante
			odom_msg.header.stamp=this->get_clock()->now();
			odom_msg.header.frame_id="odom";
			odom_msg.pose.pose.position.x = rx_buf[0]; //Posicion x actual
			odom_msg.pose.pose.position.y = rx_buf[1]; //Posicion y actual
			odom_msg.pose.pose.position.z = 0; //Posicion z actual
			
			
			tf2::Quaternion q;
			q.setRPY(0, 0, rx_buf[2]);
						
			odom_msg.pose.pose.orientation.x = q.x(); //Orientacion x actual
			odom_msg.pose.pose.orientation.y = q.y(); //Orientacion y actual
			odom_msg.pose.pose.orientation.z = q.z(); //Orientacion z actual
			odom_msg.pose.pose.orientation.w = q.w(); //Orientacion w actual//falta pasar a quaternion rx_buf[2]*180/3.14159
			
			//odom_msg.pose.covariance = 0; //Covarianza de localizacion

			odom_msg.twist.twist.linear.x = rx_buf[3]; //Velocidad x actual
			odom_msg.twist.twist.linear.y = 0; //Velocidad y actual
			odom_msg.twist.twist.linear.z = 0; //Velocidad z actual
			odom_msg.twist.twist.angular.x = 0; //Rotacion x actual
			odom_msg.twist.twist.angular.y = 0; //Rotacion y actual
			odom_msg.twist.twist.angular.z = rx_buf[4]; //Rotacion z actual
			//odom_msg.twist.covariance = 0; //Covarianza de velocidades
			//Publicacion odometria
			publisher_->publish(odom_msg);			
			
			tf2::Quaternion q_imu;
			q_imu.setRPY(0, 0, rx_buf[5]);
			
			
			imu_msg.orientation.x=q_imu.x();
			imu_msg.orientation.y=q_imu.y();
			imu_msg.orientation.z=q_imu.z();
			imu_msg.orientation.w=q_imu.w();
			
			imu_msg.angular_velocity.x=0;
			imu_msg.angular_velocity.y=0;
			imu_msg.angular_velocity.z=rx_buf[6];
			
			
			imu_msg.linear_acceleration.x=rx_buf[7];
			imu_msg.linear_acceleration.y=0;
			imu_msg.linear_acceleration.z=0;
			publisher_imu->publish(imu_msg);	
			
			
			camera_msg.data=rx_buf[8];
			publisher_camera->publish(camera_msg);		
			
			


		}
		
	}

	//Variables
	Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_;
	Subscription<std_msgs::msg::Float32>::SharedPtr subscription_camera;
	Publisher<std_msgs::msg::Float32>::SharedPtr publisher_camera;
	
	Publisher<nav_msgs::msg::Odometry>::SharedPtr publisher_;
	Publisher<sensor_msgs::msg::Imu>::SharedPtr publisher_imu;
	
	
	
	thread pub; //Thread para publicacion
	nav_msgs::msg::Odometry odom_msg; //Mensaje publicacion
	sensor_msgs::msg::Imu imu_msg; //Mensaje publicacion
	std_msgs::msg::Float32 camera_msg;
};
int main(int argc, char **argv)
{
	//Nodo ROS
	init(argc, argv);
	spin(make_shared<driver_controller>());
	
	return 0;
}
