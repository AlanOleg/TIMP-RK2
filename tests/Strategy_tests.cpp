#include <iostream>
#include <cassert>
#include <sstream>
#include <gtest/gtest.h>
#include "../strategy/Strategy.hpp"

void Context::setStrategy(Strategy* const s) {
  delete this->strategy;
  this->strategy = s;
}

void testStrategy1() { // Тест изменения стратегии во время выполнения
  Context *context = new Context(new ConcreteStrategyA());
  context->contextInterface(); // Ожидается вывод: "Concrete Strategy A"

  context->setStrategy(new ConcreteStrategyB());
  context->contextInterface(); // Ожидается вывод: "Concrete Strategy B"

  context->setStrategy(new ConcreteStrategyC());
  context->contextInterface(); // Ожидается вывод: "Concrete Strategy C"

  delete context;
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
