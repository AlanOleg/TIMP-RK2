#include <iostream>
#include <cassert>
#include <sstream>
#include <gtest/gtest.h>
#include "../strategy/Strategy.hpp"

void testStrategy1() {
  std::ostringstream stream;
  std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
  std::cout.rdbuf(stream.rdbuf());

  Context context(new ConcreteStrategyA());
  context.contextInterface();

  std::cout.rdbuf(oldCoutStreamBuf);
  assert(stream.str() == "Concrete Strategy A\n");
}

void testStrategy2() {
  Context* contextD = new Context(new ConcreteStrategyA());
  contextD->contextInterface();
  delete contextD; // Проверка освобождения памяти при уничтожении объекта Context
}

void testStrategy3() {
  std::ostringstream stream;
  std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
  std::cout.rdbuf(stream.rdbuf());

  Context context(new ConcreteStrategyC());
  context.contextInterface();

  std::cout.rdbuf(oldCoutStreamBuf);
  assert(stream.str() == "Concrete Strategy C\n");
}

int main() {
  testStrategy1();
  testStrategy2();
  testStrategy3();

  std::cout << "All tests passed!" << std::endl;

  return 0;
}
