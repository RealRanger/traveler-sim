cmake_minimum_required(VERSION 3.16)

# Project metadata
project(traveler-sim
    VERSION 0.1.0
    DESCRIPTION "Traveler — Open Source Rocket Flight Analysis & Simulation Framework"
    LANGUAGES CXX
)

# Require modern C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Add source files (adjust paths as needed)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS include/*.h include/*.hpp)

# Define the main executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})


# Include directories
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

# Example: link external libraries if needed
# find_package(Eigen3 REQUIRED)
# target_link_libraries(${PROJECT_NAME} PRIVATE Eigen3::Eigen)

# Installation rules
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
)
install(DIRECTORY include/ DESTINATION include)

# Optional: enable testing
include(CTest)
if(BUILD_TESTING AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/CMakeLists.txt")
    add_subdirectory(tests)
endif()
