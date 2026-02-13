# Top-level CMakeLists.txt
cmake_minimum_required(VERSION 3.15)
project(VitualHW)

set(GENERATED_FILE ${CMAKE_CURRENT_SOURCE_DIR}/src/sketch.cpp)
set(ORIGINAL_FILE ${CMAKE_CURRENT_SOURCE_DIR}/src/sketch.ino)
set(BUILD_SHARED_LIBS OFF) 

add_custom_command(
    OUTPUT ${GENERATED_FILE}
    COMMAND ${CMAKE_COMMAND} -E touch ${GENERATED_FILE}
    COMMAND ${CMAKE_COMMAND} -E echo "#include <main.h>" > ${GENERATED_FILE} 
    COMMAND ${CMAKE_COMMAND} -E cat ${ORIGINAL_FILE} >> ${GENERATED_FILE} 
    # COMMAND ${CMAKE_COMMAND} -E append ${GENERATED_FILE} FILE_CONTENT ${ORIGINAL_FILE}
    DEPENDS ${ORIGINAL_FILE}
    # COMMENT "Adding #include 'main.h' to sketch and renaming to sketch.cpp"
)

add_subdirectory(IntroSatLib)
add_compile_definitions(ISL_VIRTUAL)

add_executable(virtual_hw 
    src/main.cpp
    ${GENERATED_FILE}
    src/v_interface/v_debug.cpp
    src/v_core/v_core.cpp
    src/v_interface/v_i2c.cpp
    src/v_interface/v_uart.cpp
    )

target_include_directories(virtual_hw 
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/src 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/v_interface
        ${CMAKE_CURRENT_SOURCE_DIR}/src/v_core 
    # Or simply a local 'include' folder
)


target_compile_options(virtual_hw PRIVATE -std=c++20 -Wall)


# Link the library to the executable
target_link_libraries(virtual_hw PRIVATE IntroSatLib)
target_include_directories(IntroSatLib 
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/v_interface/
        # ${CMAKE_CURRENT_SOURCE_DIR}/src/v_core 
    # Or simply a local 'include' folder
)

# target_compile_options(IntroSatLib PUBLIC -std=c++14 -Wall -Wfloat-conversion)
target_compile_definitions(
  IntroSatLib
  PRIVATE
  ISL_VIRTUAL
  )

