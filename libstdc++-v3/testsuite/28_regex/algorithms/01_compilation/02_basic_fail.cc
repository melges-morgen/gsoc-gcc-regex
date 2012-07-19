// { dg-options "-std=c++0x" }

#include <regex>
#include <testsuite_hooks.h>

// The test for the compilation of expressions with brackets
// Tests that on compilation constructors throw excpetion
void 
bracket_expressions_test()
{ 
  bool test __attribute__((unused)) = true; 

  try 
  { 
    std::regex re("[z-a]", std::regex::basic); 
    VERIFY(false); 
  }
  catch (...) {
    VERIFY(true);
  }
  
  try 
  { 
    std::regex re("[]]", std::regex::basic); 
    VERIFY(false); 
  }
  catch (...) { 
    VERIFY(true);
  }
  
  try 
  { 
    std::regex re3("[a-z", std::regex::basic); 
    VERIFY(false); 
  }
  catch (...) {
    VERIFY(true);
  }
  
  try 
  { 
    std::regex re4("[", std::regex::basic); 
    VERIFY(false); 
  }
  catch (...) { 
    VERIFY(true);
  }

  try 
  { 
    std::regex re3("[a-z\\]asd", std::regex::basic); 
    VERIFY(false); 
  } 
  catch (...) { 
    VERIFY(true);
  }

  try 
  { 
    std::regex re3("[a-z\\", std::regex::basic); 
    VERIFY(false); 
  }
  catch (...) { 
    VERIFY(true);
  }

  try { 
    std::regex re3("[a-z\\]", std::regex::basic); 
    VERIFY(false); 
  }
  catch (...) { 
    VERIFY(true);
  }
}

void
interval_expressions_test() 
{
  try 
  { 
    std::regex re0("\\{1,2\\}", std::regex::basic); 
    VERIFY(false); 
  }
  catch (...) { 
    VERIFY(true);
  }
  
  try 
  { 
    std::regex re1("a\\{1,2}", std::regex::basic); 
    VERIFY(false); 
  }
  catch (...) { 
    VERIFY(true);
  }
  
  try 
  { 
    std::regex re3("a\\{1,2\\}\\{2,4\\}", std::regex::basic); 
    VERIFY(false); 
  }
  catch (...) { 
    VERIFY(true);
  }

  try 
  { 
    std::regex re4("+*", std::regex::basic); 
    VERIFY(false); 
  }
  catch (...) { 
    VERIFY(true);
  }

  try 
  {
    std::regex re5("a?+", std::regex::basic);
    VERIFY(false); 
  }
  catch (...) { 
    VERIFY(true);
  }
}

int
main()
{
  bracket_expressions_test();
  interval_expressions_test();
  return 0;
}
