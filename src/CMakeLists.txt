AUX_SOURCE_DIRECTORY(./ SRC_LIST)
ADD_EXECUTABLE(a ${SRC_LIST})
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

#include_directories(${PROJECT_SOURCE_DIR}/include)
#link_directories(${PROJECT_SOURCE_DIR}/lib)})})
#if(${CMAKE_BUILD_TYPE} MATCHES "debug")
#	target_link_libraries(hellod Ad Bd.a Cd.so)
#else()
#	target_link_libraries(hello A B.a C.so)
#endif()
#aux_source_directory(./other OTHER_SRC_LIST)))
#list(APPEND SRC_LIST ${OTHER_SRC_LIST})
#------------------opend3d------------------------------
if(WIN32)
    find_package(Open3D HINTS ${CMAKE_INSTALL_PREFIX}/CMake)
else()
    find_package(Open3D HINTS ${CMAKE_INSTALL_PREFIX}/lib/CMake)
    list(APPEND Open3D_LIBRARIES dl)
endif()
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${Open3D_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Open3D_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${Open3D_EXE_LINKER_FLAGS}")

message(STATUS "${CMAKE_CXX_FLAGS}")
# Set OS-specific things here
if(WIN32)
elseif(CYGWIN)
elseif(APPLE)
elseif(UNIX)
	add_definitions(-DUNIX)
endif(WIN32)

if (Open3D_FOUND)
    message(STATUS "Found Open3D ${Open3D_VERSION}")

    link_directories(${Open3D_LIBRARY_DIRS})
    target_link_libraries(a ${Open3D_LIBRARIES})
    target_include_directories(a PUBLIC ${Open3D_INCLUDE_DIRS})
else ()
    message(SEND_ERROR "Open3D not found")
endif ()
#----------------------------------------------------------


