set(CMAKE_CXX_FLAGS "-Wall -Werror -Wpedantic -std=c++11")

add_executable(client.out ClientMain.cpp)
add_executable(server.out ServerMain.cpp)
