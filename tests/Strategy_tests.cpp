#include <iostream>
#include <cassert>
#include <sstream>
#include <gtest/gtest.h>
#include "../strategy/Strategy.hpp"

void testStrategy1() { // Тест на исключения
  try {
    Context *context = new Context(nullptr);
    context->contextInterface();
  } catch (const std::exception &e) {
    std::cout << "Исключение поймано: " << e.what() << std::endl;
  }
}

void testStrategy2() { // Тест с несколькими контекстами
  Context *contextA = new Context(new ConcreteStrategyA());
  Context *contextB = new Context(new ConcreteStrategyB());
  Context *contextC = new Context(new ConcreteStrategyC());

  contextA->contextInterface();
  contextB->contextInterface();
  contextC->contextInterface();

  delete contextA;
  delete contextB;
  delete contextC;
}

void testStrategy3() { // Тест с проверкой вывода
  std::ostringstream stream;
  std::streambuf *oldCoutStreamBuf = std::cout.rdbuf();
  std::cout.rdbuf(stream.rdbuf());

  Context context(new ConcreteStrategyA());
  context.contextInterface();
  assert(stream.str() == "Concrete Strategy A\n");

  std::cout.rdbuf(oldCoutStreamBuf);
}

int main() {
  testStrategy1();
  testStrategy2();
  testStrategy3();

  std::cout << "All tests passed!" << std::endl;

  return 0;
}
