project(ToolboxML)

cmake_minimum_required(VERSION 2.8.11)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)


########################
## Define version

set(LINCI_MAJOR_VERSION 0)
set(LINCI_MINOR_VERSION 0)
set(LINCI_PATCH_VERSION 1)
set(LINCI_VERSION ${LINCI_MAJOR_VERSION}.${LINCI_MINOR_VERSION}.${LINCI_PATCH_VERSION})

########################
## Define install dirs

set(INSTALL_LIB_DIR     lib${LIB_SUFFIX}/ CACHE PATH "Installation directory for libraries")
set(INSTALL_INCLUDE_DIR include/          CACHE PATH "Installation directory for headers")
set(INSTALL_BIN_DIR     bin/              CACHE PATH "Installation directory for executables")
set(INSTALL_SHARE_DIR   share/ToolboxML/        CACHE PATH "Installation directory for data")
set(INSTALL_DOC_DIR     share/doc/ToolboxML/    CACHE PATH "Installation directory for documentation")

if(WIN32 AND NOT CYGWIN)
  set(DEF_INSTALL_CMAKE_DIR cmake)
else()
  set(DEF_INSTALL_CMAKE_DIR lib/cmake/ToolboxML)
endif()
set(INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH "Installation directory for CMake files")

# Make relative paths absolute (needed later on)
foreach(p LIB BIN INCLUDE SHARE DOC CMAKE)
  set(var INSTALL_${p}_DIR)
  if(NOT IS_ABSOLUTE "${${var}}")
    set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
  endif()
endforeach()

#
# Define INSTALL_TARGETS_DEFAULT_ARGS to be used as install target for program and library.
# It will do the right thing on all platform
#
set(INSTALL_TARGETS_DEFAULT_ARGS  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
                                  LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
                                  ARCHIVE DESTINATION "${INSTALL_LIB_DIR}" COMPONENT Devel )

########################
## Enable C++11 and all warnings

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")

########################
## Find Qt5

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Quick REQUIRED)

########################
## subdirectories

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(ToolboxML)

########################
## Config files

export(TARGETS ToolboxML
  FILE "${PROJECT_BINARY_DIR}/ToolboxMLTargets.cmake")

# Export the package for use from the build-tree
# (this registers the build-tree with a global CMake-registry)
export(PACKAGE ToolboxML)

# Create the ToolboxMLConfig.cmake and ToolboxMLConfigVersion files
file(RELATIVE_PATH REL_INCLUDE_DIR "${INSTALL_CMAKE_DIR}"
   "${INSTALL_INCLUDE_DIR}")

# ... for the install tree
set(CONF_INCLUDE_DIRS "\${KDB_CMAKE_DIR}/${REL_INCLUDE_DIR}")
configure_file(ToolboxMLConfig.cmake.in
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/ToolboxMLConfig.cmake" @ONLY)
configure_file(ToolboxMLConfigVersion.cmake.in
  "${PROJECT_BINARY_DIR}/ToolboxMLConfigVersion.cmake" @ONLY)
 
# Install the ToolboxMLConfig.cmake and ToolboxMLConfigVersion.cmake
install(FILES
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/ToolboxMLConfig.cmake"
  "${PROJECT_BINARY_DIR}/ToolboxMLConfigVersion.cmake"
  DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)
 
# Install the export set for use with the install-tree
install(EXPORT ToolboxMLTargets DESTINATION
  "${INSTALL_CMAKE_DIR}" COMPONENT dev)
