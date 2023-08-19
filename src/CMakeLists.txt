
file(GLOB CPP_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB HPP_FILES ${CMAKE_SOURCE_DIR}/src/*.h)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-g")
include_directories(${CMAKE_SOURCE_DIR}/src)

message(STATUS ${CPP_FILES})

add_executable(cpp_object_model_experiment ${CPP_FILES} ${HPP_FILES})