cmake_minimum_required(VERSION 3.22)
project(upstream_c VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

find_package(upstream_b 0.1 REQUIRED)

add_library(upstream_c SHARED src/upstream_c.cpp)
add_library(upstream_c::upstream_c ALIAS upstream_c)
target_include_directories(upstream_c PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_link_libraries(upstream_c PRIVATE upstream_b::upstream_b)

install(TARGETS upstream_c EXPORT upstream_cTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT upstream_cTargets NAMESPACE upstream_c::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/upstream_c)
configure_package_config_file(cmake/upstream_cConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/upstream_cConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/upstream_c)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/upstream_cConfigVersion.cmake
  COMPATIBILITY SameMajorVersion)
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/upstream_cConfig.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/upstream_cConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/upstream_c)

include(CTest)
if(BUILD_TESTING)
  find_package(GTest REQUIRED)
  add_executable(test_upstream_c test/test_upstream_c.cpp)
  target_link_libraries(test_upstream_c PRIVATE upstream_c GTest::gtest_main)
  add_test(NAME test_upstream_c COMMAND test_upstream_c)
endif()
