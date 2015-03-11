# Install script for directory: /Users/sens/Developer/mysql-5.6.23

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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Info")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/docs" TYPE FILE OPTIONAL FILES "/Users/sens/Developer/mysql-5.6.23/Docs/mysql.info")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Readme")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE OPTIONAL FILES
    "/Users/sens/Developer/mysql-5.6.23/COPYING"
    "/Users/sens/Developer/mysql-5.6.23/LICENSE.mysql"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Readme")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "/Users/sens/Developer/mysql-5.6.23/README")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/docs" TYPE FILE FILES
    "/Users/sens/Developer/mysql-5.6.23/project/Docs/INFO_SRC"
    "/Users/sens/Developer/mysql-5.6.23/project/Docs/INFO_BIN"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Readme")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "/Users/sens/Developer/mysql-5.6.23/Docs/INSTALL-BINARY")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Documentation")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/docs" TYPE DIRECTORY FILES "/Users/sens/Developer/mysql-5.6.23/Docs/" REGEX "/install\\-binary$" EXCLUDE REGEX "/makefile\\.[^/]*$" EXCLUDE REGEX "/glibc[^/]*$" EXCLUDE REGEX "/linuxthreads\\.txt$" EXCLUDE REGEX "/myisam\\.txt$" EXCLUDE REGEX "/mysql\\.info$" EXCLUDE REGEX "/sp\\-imp\\-spec\\.txt$" EXCLUDE)
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/sens/Developer/mysql-5.6.23/project/zlib/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/extra/yassl/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/extra/yassl/taocrypt/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/cmd-line-utils/libedit/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/libevent/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/storage/archive/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/storage/blackhole/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/storage/csv/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/storage/example/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/storage/federated/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/storage/heap/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/storage/innobase/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/storage/myisam/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/storage/myisammrg/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/storage/ndb/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/storage/perfschema/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/plugin/audit_null/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/plugin/auth/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/plugin/daemon_example/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/plugin/fulltext/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/plugin/innodb_memcached/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/plugin/password_validation/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/plugin/semisync/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/include/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/dbug/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/strings/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/vio/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/regex/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/mysys/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/mysys_ssl/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/libmysql/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/unittest/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/unittest/examples/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/unittest/mytap/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/unittest/mytap/t/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/unittest/gunit/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/extra/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/client/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/sql/share/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/libservices/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/man/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/tests/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/sql/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/libmysqld/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/libmysqld/examples/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/scripts/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/mysql-test/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/mysql-test/lib/My/SafeProcess/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/support-files/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/sql-bench/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/packaging/rpm-oel/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/packaging/rpm-fedora/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/packaging/rpm-sles/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/packaging/WiX/cmake_install.cmake")
  include("/Users/sens/Developer/mysql-5.6.23/project/packaging/solaris/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

file(WRITE "/Users/sens/Developer/mysql-5.6.23/project/${CMAKE_INSTALL_MANIFEST}" "")
foreach(file ${CMAKE_INSTALL_MANIFEST_FILES})
  file(APPEND "/Users/sens/Developer/mysql-5.6.23/project/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
endforeach()
