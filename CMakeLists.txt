cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)

project(Strategy)

add_executable(Strategy Strategy.cpp)

option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
  enable_testing()  # Включаем поддержку тестирования.
  file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)  # Получаем исходные файлы тестов.
  add_subdirectory(third-party/gtest) # Добавление библиотеки Google Test
  add_executable(RunTests ${${PROJECT_NAME}_TEST_SOURCES})  # Создаем исполняемый файл для тестов.
  target_link_libraries(RunTests gtest_main)  # Линкуем библиотеки для тестов.
  add_test(NAME RunTests COMMAND RunTests)  # Добавляем команду для запуска тестов.
endif()
