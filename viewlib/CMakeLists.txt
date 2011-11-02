PROJECT(viewlib)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)


# Find modules

# First extend CMake module path
OPTION(EXTEND_CMAKE_MODULE_PATH 
  "Extend the CMAKE_MODULE_PATH variable with user directories?" ON)
IF(EXTEND_CMAKE_MODULE_PATH)
  SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} 
    ${CMAKE_HOME_DIRECTORY}/cmake/Modules
    ${CMAKE_INSTALL_PREFIX}/share/cmake/Modules
    "./cmake/Modules"
    "~/cmake/Modules"
    "C:/cmake/Modules")
ENDIF(EXTEND_CMAKE_MODULE_PATH)

FIND_PACKAGE(GoIgeslib REQUIRED)
FIND_PACKAGE(GoTools REQUIRED)
FIND_PACKAGE(SISL REQUIRED)
FIND_PACKAGE(OpenGL REQUIRED)

FIND_PACKAGE(Qt4 REQUIRED)

IF(WIN32)
  SET(GLUT_INCLUDE_DIR
    "$ENV{PROGRAMW6432}/Microsoft SDKs/Windows/v6.0A/Include"
    )
ELSE(WIN32)
  FIND_PACKAGE(GLUT REQUIRED)
ENDIF(WIN32)

SET(QT_USE_QTOPENGL 1)
SET(QT_USE_QT3SUPPORT 1)
INCLUDE(${QT_USE_FILE})


# Include directories

INCLUDE_DIRECTORIES(
  ${viewlib_BINARY_DIR}
  ${viewlib_SOURCE_DIR}/include
  ${GoIgeslib_INCLUDE_DIRS}
  ${GoTools_INCLUDE_DIRS}
  ${SISL_INCLUDE_DIRS}
  ${QT_INCLUDES}
  ${OPENGL_INCLUDE_DIR}
  ${GLUT_INCLUDE_DIR}
  )


# Linked in libraries

SET(DEPLIBS
  ${GoIgeslib_LIBRARIES}
  ${GoTools_LIBRARIES}
  ${SISL_LIBRARIES}
  ${QT_LIBRARIES}
  ${OPENGL_LIBRARIES}
  )


# Qt uic
FILE(GLOB_RECURSE viewlib_UIS include/*.ui)
QT4_WRAP_UI(viewlib_UIS_H ${viewlib_UIS})


# Qt moc. The option '-nw' is "not recommended" according to the Qt
# documentation, but it gets rid of warnings...
FILE(GLOB_RECURSE viewlib_MOC_HDRS_TMP include/*.h)
SET(viewlib_MOC_HDRS ${viewlib_MOC_HDRS_TMP} ${viewlib_UIS_H})
QT4_WRAP_CPP(viewlib_MOC_SRCS ${viewlib_MOC_HDRS}
  OPTIONS "-nw")


# Make the viewlib library

FILE(GLOB_RECURSE viewlib_SRCS src/*.C include/*.h)
ADD_LIBRARY(viewlib ${viewlib_SRCS} ${viewlib_MOC_SRCS})
TARGET_LINK_LIBRARIES(viewlib ${DEPLIBS})


# Set various compiler flags

IF(NOT WIN32)
  # Set warning level to '-Wall' on Linux
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")
ELSE(NOT WIN32)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP8
  -D_SCL_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_WARNINGS")
ENDIF(NOT WIN32)

# Get rid of MESSAGEs in Release mode
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNVERBOSE")


# Apps, examples, tests, ...?

FILE(GLOB viewlib_APPS app/*.C)
FOREACH(app ${viewlib_APPS})
  GET_FILENAME_COMPONENT(appname ${app} NAME_WE)
  ADD_EXECUTABLE(${appname} ${app})
  TARGET_LINK_LIBRARIES(${appname} viewlib ${DEPLIBS})
ENDFOREACH(app)

# Copy data
ADD_CUSTOM_COMMAND(
  TARGET viewlib
  POST_BUILD
  COMMAND ${CMAKE_COMMAND}
  ARGS -E copy_directory ${viewlib_SOURCE_DIR}/data
  ${viewlib_BINARY_DIR}/data
  )


# 'install' target
IF(WIN32)
  # Windows
  SET(CMAKE_INSTALL_PREFIX CACHE INTERNAL "")
  SET(GoTools_INSTALL_PREFIX "$ENV{PROGRAMFILES}/SINTEF/GoTools"
    CACHE PATH "Path to install GoTools viewlib")
  # lib
  INSTALL(TARGETS viewlib DESTINATION ${GoTools_INSTALL_PREFIX}/lib)
  # include
  INSTALL(DIRECTORY include/GoTools/viewlib
    DESTINATION ${GoTools_INSTALL_PREFIX}/include/GoTools
    FILES_MATCHING PATTERN "*.h"
    PATTERN ".svn" EXCLUDE
    )
  # data
  INSTALL(DIRECTORY data/
    DESTINATION ${GoTools_INSTALL_PREFIX}/share/viewlib
    FILES_MATCHING PATTERN "*.g2" PATTERN "*.igs"
    PATTERN ".svn" EXCLUDE
    )
  # bin
  SET(goview_INSTALL_PREFIX "$ENV{PROGRAMFILES}/SINTEF/goview"
    CACHE PATH "Path to install goview")
  INSTALL(TARGETS goview DESTINATION ${goview_INSTALL_PREFIX})
ELSE(WIN32)
  # Linux
  # lib
  INSTALL(TARGETS viewlib DESTINATION lib/GoTools)
  # include
  INSTALL(DIRECTORY include/GoTools/viewlib
    DESTINATION include/GoTools
    FILES_MATCHING PATTERN "*.h"
    PATTERN ".svn" EXCLUDE
    )
  # data
  INSTALL(DIRECTORY data/
    DESTINATION share/GoTools/viewlib
    FILES_MATCHING PATTERN "*.g2" PATTERN "*.igs"
    PATTERN ".svn" EXCLUDE
    )
  # bin
  INSTALL(TARGETS goview DESTINATION bin)
ENDIF(WIN32)