cmake_minimum_required(VERSION 2.8)

project(simuli)

set(EXECUTABLE_NAME simuli)

set(simuli_SRC
      src/Figures/Detail.cxx
      src/Render.cxx
      src/main.cxx)

include_directories(include/)

add_executable(${EXECUTABLE_NAME} ${simuli_SRC})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
# Find any version 2.X of SFML
# See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()