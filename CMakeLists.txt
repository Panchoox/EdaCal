cmake_minimum_required(VERSION 3.10)
project(EdaCal VERSION 1.0.0 LANGUAGES CXX)

# Configuración del estándar C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Directorio de inclusión
include_directories(${PROJECT_SOURCE_DIR}/include)

# Archivos fuente de la biblioteca
set(LIBRARY_SOURCES
    src/node.cpp
    src/linked_list.cpp
    src/stack.cpp
    src/expression_tree.cpp
    src/calculator.cpp
    src/utils.cpp
)

# Crear biblioteca estática
add_library(edacal_lib STATIC ${LIBRARY_SOURCES})

# Ejecutable principal
add_executable(edacal main.cpp)
target_link_libraries(edacal edacal_lib)

# Tests
enable_testing()

# Test LinkedList
add_executable(test_linked_list tests/test_linked_list.cpp)
target_link_libraries(test_linked_list edacal_lib)
add_test(NAME LinkedListTest COMMAND test_linked_list)

# Test Stack
add_executable(test_stack tests/test_stack.cpp)
target_link_libraries(test_stack edacal_lib)
add_test(NAME StackTest COMMAND test_stack)

# Test ExpressionTree
add_executable(test_tree tests/test_tree.cpp)
target_link_libraries(test_tree edacal_lib)
add_test(NAME TreeTest COMMAND test_tree)

# Test Calculator
add_executable(test_calculator tests/test_calculator.cpp)
target_link_libraries(test_calculator edacal_lib)
add_test(NAME CalculatorTest COMMAND test_calculator)

# Configuración de compilación
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(edacal_lib PRIVATE -Wall -Wextra -pedantic)
endif()

# Mensajes informativos
message(STATUS "EdaCal version: ${PROJECT_VERSION}")
message(STATUS "C++ standard: ${CMAKE_CXX_STANDARD}")
