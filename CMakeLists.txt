# the alternative to compiling would be...
# g++ -isystem ${GTEST_DIR}/include -pthread path/to/your_test.cc libgtest.a -o your_test
cmake_minimum_required(VERSION 2.6)

project(Network_CPP)

add_subdirectory(src ./bin)
