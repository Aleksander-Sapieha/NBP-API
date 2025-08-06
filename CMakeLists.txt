cmake_minimum_required(VERSION 3.10)
project(nbp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add external libraries
add_subdirectory(external/cpr)
add_subdirectory(external/json)

add_executable(nbp main.cpp api.cpp)

# Link libraries
target_link_libraries(nbp PRIVATE 
    cpr::cpr 
    nlohmann_json::nlohmann_json
)
