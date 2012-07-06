#include <regex>
#include <stdio.h>

int main () {
  std::regex re("a\\{0,3\\}[a-c]", std::regex::basic);
  std::string target_true ("ab");
  std::string target_false("f");
  std::smatch m;

  if (std::regex_match(target_true, m, re))
    printf ("accept is working!\n");
  else
    printf ("accept failed!\n");

  if (!std::regex_match(target_false, m, re))
    printf ("reject is working!\n");
  else
    printf ("reject failed!\n");

  return 0;
}
