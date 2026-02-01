# Top-level CMakeLists.txt
cmake_minimum_required(VERSION 3.15)
project(MyApp)

# Add the library as a subdirectory
add_subdirectory(IntroSatLib)

# Add the executable
add_executable(my_app 
    src/main.cpp
    src/sketch.cpp
    )

target_include_directories(my_app 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/src 
    # Or simply a local 'include' folder
)
target_compile_options(my_app PUBLIC -std=c++20 -Wall -Wfloat-conversion)


# Link the library to the executable
target_link_libraries(my_app PUBLIC IntroSatLib)
# target_compile_options(IntroSatLib PUBLIC -std=c++14 -Wall -Wfloat-conversion)
target_compile_definitions(
  IntroSatLib
  PUBLIC
  ISL_VIRTUAL
  )