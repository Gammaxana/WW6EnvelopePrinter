cmake_minimum_required (VERSION 3.8)

project ("AddressSortAndPrint")

add_subdirectory (lib/OpenXLSX)

add_executable (AddressSortAndPrint "AddressSortAndPrint.cpp" )

target_link_libraries(AddressSortAndPrint PUBLIC OpenXLSX-static)

set_target_properties(AddressSortAndPrint PROPERTIES CXX_STANDARD 17 CXX_EXTENSIONS OFF)