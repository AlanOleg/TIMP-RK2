#include <iostream>
#include <cassert>
#include <sstream>
#include <gtest/gtest.h>
#include "../strategy/Strategy.hpp"

// Ваши классы Strategy, ConcreteStrategyA, ConcreteStrategyB, ConcreteStrategyC и Context здесь...

void testStrategyA() {
  std::ostringstream stream;
  std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
  std::cout.rdbuf(stream.rdbuf());

  Context context(new ConcreteStrategyA());
  context.contextInterface();

  std::cout.rdbuf(oldCoutStreamBuf);
  assert(stream.str() == "Concrete Strategy A\n");
}

void testStrategyB() {
  std::ostringstream stream;
  std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
  std::cout.rdbuf(stream.rdbuf());

  Context context(new ConcreteStrategyB());
  context.contextInterface();

  std::cout.rdbuf(oldCoutStreamBuf);
  assert(stream.str() == "Concrete Strategy B\n");
}

void testStrategyC() {
  std::ostringstream stream;
  std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
  std::cout.rdbuf(stream.rdbuf());

  Context context(new ConcreteStrategyC());
  context.contextInterface();

  std::cout.rdbuf(oldCoutStreamBuf);
  assert(stream.str() == "Concrete Strategy C\n");
}

int main() {
  testStrategyA();
  testStrategyB();
  testStrategyC();

  std::cout << "All tests passed!" << std::endl;

  return 0;
}
