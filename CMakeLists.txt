cmake_minimum_required (VERSION 3.8)

project ("CMakeProject1")

add_subdirectory (lib/OpenXLSX)

add_executable (CMakeProject1 "CMakeProject1.cpp" )

target_link_libraries(CMakeProject1 PUBLIC OpenXLSX-static)

set_target_properties(CMakeProject1 PROPERTIES CXX_STANDARD 17 CXX_EXTENSIONS OFF)