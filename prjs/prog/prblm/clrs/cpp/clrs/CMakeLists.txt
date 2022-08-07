cmake_minimum_required(VERSION 3.13)

# set the project name
project(CLRS)


add_library(clrs "")
add_executable(clrslibtest "")
add_dependencies(clrslibtest clrs)
target_link_libraries(clrslibtest clrs)


# include sources in subdirectories
add_subdirectory(part7/chap32)
enable_testing()
## define test to execute
add_test(NAME clrstest COMMAND clrslibtest)
#add_custom_target(check COMMAND clrslibtest)
