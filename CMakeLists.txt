cmake_minimum_required(VERSION 3.14) # FetchContent works best >= 3.14
project(nbp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# nlohmann_json (header-only)
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(nlohmann_json)

# cpr
FetchContent_Declare(
    cpr
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG 1.10.5
)
set(CPR_BUILD_TESTS OFF CACHE BOOL "Don't build cpr tests" FORCE)
FetchContent_MakeAvailable(cpr)

add_executable(nbp main.cpp api.cpp)

target_link_libraries(nbp PRIVATE
    cpr::cpr
    nlohmann_json::nlohmann_json
)
