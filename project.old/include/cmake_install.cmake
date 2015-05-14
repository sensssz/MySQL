# Install script for directory: /Users/sens/Developer/mysql-5.6.23/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local/mysql")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/Users/sens/Developer/mysql-5.6.23/include/mysql.h"
    "/Users/sens/Developer/mysql-5.6.23/include/mysql_com.h"
    "/Users/sens/Developer/mysql-5.6.23/include/mysql_time.h"
    "/Users/sens/Developer/mysql-5.6.23/include/my_list.h"
    "/Users/sens/Developer/mysql-5.6.23/include/my_alloc.h"
    "/Users/sens/Developer/mysql-5.6.23/include/typelib.h"
    "/Users/sens/Developer/mysql-5.6.23/include/mysql/plugin.h"
    "/Users/sens/Developer/mysql-5.6.23/include/mysql/plugin_audit.h"
    "/Users/sens/Developer/mysql-5.6.23/include/mysql/plugin_ftparser.h"
    "/Users/sens/Developer/mysql-5.6.23/include/mysql/plugin_validate_password.h"
    "/Users/sens/Developer/mysql-5.6.23/include/my_dbug.h"
    "/Users/sens/Developer/mysql-5.6.23/include/m_string.h"
    "/Users/sens/Developer/mysql-5.6.23/include/my_sys.h"
    "/Users/sens/Developer/mysql-5.6.23/include/my_xml.h"
    "/Users/sens/Developer/mysql-5.6.23/include/mysql_embed.h"
    "/Users/sens/Developer/mysql-5.6.23/include/my_pthread.h"
    "/Users/sens/Developer/mysql-5.6.23/include/decimal.h"
    "/Users/sens/Developer/mysql-5.6.23/include/errmsg.h"
    "/Users/sens/Developer/mysql-5.6.23/include/my_global.h"
    "/Users/sens/Developer/mysql-5.6.23/include/my_net.h"
    "/Users/sens/Developer/mysql-5.6.23/include/my_getopt.h"
    "/Users/sens/Developer/mysql-5.6.23/include/sslopt-longopts.h"
    "/Users/sens/Developer/mysql-5.6.23/include/my_dir.h"
    "/Users/sens/Developer/mysql-5.6.23/include/sslopt-vars.h"
    "/Users/sens/Developer/mysql-5.6.23/include/sslopt-case.h"
    "/Users/sens/Developer/mysql-5.6.23/include/sql_common.h"
    "/Users/sens/Developer/mysql-5.6.23/include/keycache.h"
    "/Users/sens/Developer/mysql-5.6.23/include/m_ctype.h"
    "/Users/sens/Developer/mysql-5.6.23/include/my_attribute.h"
    "/Users/sens/Developer/mysql-5.6.23/include/my_compiler.h"
    "/Users/sens/Developer/mysql-5.6.23/include/mysql_com_server.h"
    "/Users/sens/Developer/mysql-5.6.23/include/my_byteorder.h"
    "/Users/sens/Developer/mysql-5.6.23/include/byte_order_generic.h"
    "/Users/sens/Developer/mysql-5.6.23/include/byte_order_generic_x86.h"
    "/Users/sens/Developer/mysql-5.6.23/include/byte_order_generic_x86_64.h"
    "/Users/sens/Developer/mysql-5.6.23/include/little_endian.h"
    "/Users/sens/Developer/mysql-5.6.23/include/big_endian.h"
    "/Users/sens/Developer/mysql-5.6.23/project/include/mysql_version.h"
    "/Users/sens/Developer/mysql-5.6.23/project/include/my_config.h"
    "/Users/sens/Developer/mysql-5.6.23/project/include/mysqld_ername.h"
    "/Users/sens/Developer/mysql-5.6.23/project/include/mysqld_error.h"
    "/Users/sens/Developer/mysql-5.6.23/project/include/sql_state.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/mysql" TYPE DIRECTORY FILES "/Users/sens/Developer/mysql-5.6.23/include/mysql/" REGEX "/[^/]*\\.h$" REGEX "/psi\\_abi[^/]*$" EXCLUDE)
endif()

