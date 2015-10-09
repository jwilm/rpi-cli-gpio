# Library
add_library(gpio STATIC
    options.cpp
    )

# Executable
add_executable(gpio_exe main.cpp)
set_target_properties(gpio_exe PROPERTIES OUTPUT_NAME gpio)
target_link_libraries(gpio_exe PRIVATE gpio)
