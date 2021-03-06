PROJECT(GoTrivariate)


# Include directories

INCLUDE_DIRECTORIES(
  ${GoTrivariate_SOURCE_DIR}/include
  ${GoToolsCore_SOURCE_DIR}/include
  ${GoTools_COMMON_INCLUDE_DIRS}
  )


# Linked in libraries

SET(DEPLIBS
  GoToolsCore
  sisl
  )


# Make the GoTrivariate library

FILE(GLOB_RECURSE GoTrivariate_SRCS src/*.C include/*.h)
if (BUILD_AS_SHARED_LIBRARY)
    ADD_LIBRARY(GoTrivariate SHARED ${GoTrivariate_SRCS})
else (BUILD_AS_SHARED_LIBRARY)
    ADD_LIBRARY(GoTrivariate ${GoTrivariate_SRCS})
endif (BUILD_AS_SHARED_LIBRARY)
TARGET_LINK_LIBRARIES(GoTrivariate ${DEPLIBS})
SET_PROPERTY(TARGET GoTrivariate
  PROPERTY FOLDER "GoTrivariate/Libs")
SET_TARGET_PROPERTIES(GoTrivariate PROPERTIES SOVERSION ${GoTools_ABI_VERSION})


# Apps, examples, tests, ...?

IF(GoTools_COMPILE_APPS)
  FILE(GLOB_RECURSE GoTrivariate_APPS app/*.C)
  FOREACH(app ${GoTrivariate_APPS})
    GET_FILENAME_COMPONENT(appname ${app} NAME_WE)
    ADD_EXECUTABLE(${appname} ${app})
    TARGET_LINK_LIBRARIES(${appname} GoTrivariate ${DEPLIBS})
    SET_TARGET_PROPERTIES(${appname}
      PROPERTIES RUNTIME_OUTPUT_DIRECTORY app)
    SET_PROPERTY(TARGET ${appname}
      PROPERTY FOLDER "GoTrivariate/Apps")
  ENDFOREACH(app)

  FILE(GLOB_RECURSE GoTrivariate_EXAMPLES examples/*.C)
  FOREACH(app ${GoTrivariate_EXAMPLES})
    GET_FILENAME_COMPONENT(appname ${app} NAME_WE)
    ADD_EXECUTABLE(${appname} ${app})
    TARGET_LINK_LIBRARIES(${appname} GoTrivariate ${DEPLIBS})
    SET_TARGET_PROPERTIES(${appname}
      PROPERTIES RUNTIME_OUTPUT_DIRECTORY examples)
    SET_PROPERTY(TARGET ${appname}
      PROPERTY FOLDER "GoTrivariate/Examples")
  ENDFOREACH(app)
ENDIF(GoTools_COMPILE_APPS)

# 'install' target

IF(WIN32)
  # Windows
  # lib
  INSTALL(TARGETS GoTrivariate DESTINATION ${GoTools_INSTALL_PREFIX}/lib)
  # include
  INSTALL(DIRECTORY include/GoTools/trivariate
    DESTINATION ${GoTools_INSTALL_PREFIX}/include/GoTools
    FILES_MATCHING PATTERN "*.h"
    PATTERN ".svn" EXCLUDE
    )
ELSE(WIN32)
  # Linux
  # lib
  INSTALL(TARGETS GoTrivariate DESTINATION lib COMPONENT trivariate)
  # include
  INSTALL(DIRECTORY include/GoTools/trivariate
    DESTINATION include/GoTools
    COMPONENT trivariate-dev
    FILES_MATCHING PATTERN "*.h"
    PATTERN ".svn" EXCLUDE
    )
ENDIF(WIN32)

SET(CPACK_STRIP_FILES ${CPACK_STRIP_FILES} libGoTrivariate.so)
