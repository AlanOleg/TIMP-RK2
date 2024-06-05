#include <iostream>

int main()
{
  Context context( new ConcreteStrategyA() );
  context.contextInterface();
  
  return 0;
}
