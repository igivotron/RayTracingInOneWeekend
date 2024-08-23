cmake_minimum_required(VERSION 3.0.0)
project(RayTracingInOneWeekend VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
#enable_testing()

add_executable(main main.cc)

set_property(TARGET main PROPERTY CXX_STANDARD 17)