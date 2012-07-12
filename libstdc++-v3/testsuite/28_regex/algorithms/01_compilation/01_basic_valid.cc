#include <regex>
#include <testsuite_hooks.h>

// Test on a compilation of simple expressions.
void 
simple_string_test()
{
  std::regex re0("Simple string", std::regex::basic);
  std::regex re1("String[a-z] string", std::regex::basic);
  std::regex re2("String[a-zA-Z-]", std::regex::basic);
  std::regex re3("\\[a-z\\]", std::regex::basic);
  std::regex re4("(\\[\\[a-z\\]\\])*", std::regex::basic);
  std::regex re5("a(([a-z]))", std::regex::basic);
  std::regex re6("(),))(,)(((", std::regex::basic);
  std::regex re7("\\[\\[\\[\\[\\]", std::regex::basic);
  std::regex re8("", std::regex::basic);
  std::regex re9("(ss)s{s,s}\\[dd\\]", std::regex::basic);
  std::regex re10("((ss}}\\a\\s", std::regex::basic);
}

// The test for the compilation of expressions with brackets
void 
bracket_expressions_test()
{
  std::regex re0("[]", std::regex::basic);
  std::regex re1("[a-z]", std::regex::basic);
  std::regex re2("[az-]", std::regex::basic);
  std::regex re3("[-za]", std::regex::basic);
  std::regex re4("[a-zA-Z]", std::regex::basic);
  std::regex re5("[a-z-A-Z]", std::regex::basic);
  std::regex re6("[\\]a-z]", std::regex::basic);
  std::regex re7("[a\\-z\\]]", std::regex::basic);
  std::regex re8("[-]", std::regex::basic);
  std::regex re9("[a-]", std::regex::basic);
  std::regex re10("[-a]", std::regex::basic);
  std::regex re11("[abce{asdf}a-h\\]\\[]", std::regex::basic);
}

void
interval_expressions_test() 
{
  std::regex re0("a\\{,4\\}", std::regex::basic);
  std::regex re1("a\\{2,4\\}", std::regex::basic);
  std::regex re2("a\\{2,\\}", std::regex::basic);
  std::regex re3("a*", std::regex::basic);
  std::regex re4("a+", std::regex::basic);
  std::regex re5("a?", std::regex::basic);
  std::regex re6("a?b?c+", std::regex::basic);
  std::regex re7("\\++\\?+\\??\\+?", std::regex::basic);
}

int
main()
{
  simple_string_test();
  bracket_expressions_test();
  interval_expressions_test();
  return 0;
}
