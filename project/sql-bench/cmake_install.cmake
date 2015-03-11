# Install script for directory: /Users/sens/Developer/mysql-5.6.23/sql-bench

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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench/Data" TYPE DIRECTORY FILES "/Users/sens/Developer/mysql-5.6.23/sql-bench/Data/ATIS")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench/Data" TYPE DIRECTORY FILES "/Users/sens/Developer/mysql-5.6.23/sql-bench/Data/Wisconsin")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE DIRECTORY FILES "/Users/sens/Developer/mysql-5.6.23/sql-bench/limits")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE PROGRAM FILES "/Users/sens/Developer/mysql-5.6.23/project/sql-bench/bench-count-distinct")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE PROGRAM FILES "/Users/sens/Developer/mysql-5.6.23/project/sql-bench/bench-init.pl")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE PROGRAM FILES "/Users/sens/Developer/mysql-5.6.23/project/sql-bench/compare-results")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE PROGRAM FILES "/Users/sens/Developer/mysql-5.6.23/project/sql-bench/copy-db")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE PROGRAM FILES "/Users/sens/Developer/mysql-5.6.23/project/sql-bench/crash-me")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE PROGRAM FILES "/Users/sens/Developer/mysql-5.6.23/project/sql-bench/graph-compare-results")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE PROGRAM FILES "/Users/sens/Developer/mysql-5.6.23/project/sql-bench/innotest1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE PROGRAM FILES "/Users/sens/Developer/mysql-5.6.23/project/sql-bench/innotest1a")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE PROGRAM FILES "/Users/sens/Developer/mysql-5.6.23/project/sql-bench/innotest1b")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE PROGRAM FILES "/Users/sens/Developer/mysql-5.6.23/project/sql-bench/innotest2")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE PROGRAM FILES "/Users/sens/Developer/mysql-5.6.23/project/sql-bench/innotest2a")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE PROGRAM FILES "/Users/sens/Developer/mysql-5.6.23/project/sql-bench/innotest2b")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE FILE FILES "/Users/sens/Developer/mysql-5.6.23/project/sql-bench/README")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE PROGRAM FILES "/Users/sens/Developer/mysql-5.6.23/project/sql-bench/run-all-tests")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE PROGRAM FILES "/Users/sens/Developer/mysql-5.6.23/project/sql-bench/server-cfg")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE PROGRAM FILES "/Users/sens/Developer/mysql-5.6.23/project/sql-bench/test-alter-table")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE PROGRAM FILES "/Users/sens/Developer/mysql-5.6.23/project/sql-bench/test-ATIS")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE PROGRAM FILES "/Users/sens/Developer/mysql-5.6.23/project/sql-bench/test-big-tables")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE PROGRAM FILES "/Users/sens/Developer/mysql-5.6.23/project/sql-bench/test-connect")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE PROGRAM FILES "/Users/sens/Developer/mysql-5.6.23/project/sql-bench/test-create")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE PROGRAM FILES "/Users/sens/Developer/mysql-5.6.23/project/sql-bench/test-insert")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE PROGRAM FILES "/Users/sens/Developer/mysql-5.6.23/project/sql-bench/test-select")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE PROGRAM FILES "/Users/sens/Developer/mysql-5.6.23/project/sql-bench/test-transactions")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "SqlBench")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/sql-bench" TYPE PROGRAM FILES "/Users/sens/Developer/mysql-5.6.23/project/sql-bench/test-wisconsin")
endif()

