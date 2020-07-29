cmake_minimum_required(VERSION 3.5)
project(circbuf VERSION 0.1.0)
# import install variables package
include (GNUInstallDirs)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add target
add_library(circbuf SHARED src/circbuf.cpp)

target_include_directories(circbuf PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/>
)

set_target_properties(circbuf PROPERTIES PUBLIC_HEADER include/circbuf/circbuf.hpp)
install(TARGETS ${PROJECT_NAME}
        EXPORT circbufConfig
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/circbuf
        LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(EXPORT circbufConfig DESTINATION share/circbuf/cmake)
export(TARGETS ${PROJECT_NAME} FILE circbufConfig.cmake)

# add test executable
add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE circbuf)
install(TARGETS main
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
