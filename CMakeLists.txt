cmake_minimum_required(VERSION 3.10)
project(SolarSystem)


# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directory
include_directories(include)


#Our project
set(SOURCE_FILES
    src/main.cpp
    src/Planet.cpp
    src/SolarSystem.cpp)
    
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# 2. Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# 3. Link AFTER add_executable
target_link_libraries(SolarSystem
    sfml-graphics
    sfml-window
    sfml-system
)
