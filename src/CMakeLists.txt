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

