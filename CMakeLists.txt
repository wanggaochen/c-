cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 11)
#包含文件
add_executable(untitled main.cpp arithmetic/arithmetic.cpp arithmetic/arithmetic.h my_selfString/my_selfString.h my_selfString/my_selfString.cpp head.h file/file.cpp file/file.h pool/process.cpp pool/process.h pool/pthread.cpp pool/pthread.h log/log.cpp log/log.h common/singletemplate.h structClass/datatype.cpp structClass/datatype.h mysql/my_mysql.cpp mysql/my_mysql.h net/net.h)