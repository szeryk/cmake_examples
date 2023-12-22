add_executable(HelloWorldPrinterTest hello_world_printer_test.cpp)
target_link_libraries(HelloWorldPrinterTest PRIVATE HelloWorldPrinter)

add_test(NAME HelloWorldUnitTest COMMAND HelloWorldPrinterTest)
set_tests_properties(HelloWorldUnitTest PROPERTIES
    PASS_REGULAR_EXPRESSION "Hello.*world"
)
