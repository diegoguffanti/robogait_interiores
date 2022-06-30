cmake_minimum_required( VERSION 3.6 )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

project( K4ABT )
add_executable( K4ABT main.cpp )

set_property( DIRECTORY PROPERTY VS_STARTUP_PROJECT "K4ABT" )

set( CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}" ${CMAKE_MODULE_PATH} )
find_package( k4a REQUIRED )
find_package( k4abt REQUIRED )

if( k4a_FOUND AND k4abt_FOUND )
  target_link_libraries( K4ABT k4a::k4a )
  target_link_libraries( K4ABT k4a::k4abt )
endif()
