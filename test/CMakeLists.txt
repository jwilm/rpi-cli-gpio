set(TEST_INCLUDES ../src)

enable_testing()

macro(create_test MAINFILE)
    add_test(NAME ${MAINFILE} COMMAND test_${MAINFILE})
    add_executable(test_${MAINFILE} ${MAINFILE}.cpp)
    target_include_directories(test_${MAINFILE} PRIVATE ${TEST_INCLUDES})
    target_link_libraries(test_${MAINFILE} gpio)
endmacro(create_test)

create_test(parse_options)
