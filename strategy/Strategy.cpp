#include <iostream>
#include "../Strategy.hpp"

int main()
{
  Context context( new ConcreteStrategyA() );
  context.contextInterface();
  
  return 0;
}
