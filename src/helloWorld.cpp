#include <iostream>
#include <ostream>
#include <fmt/format.h>

int main() {
  std::cout << "Hello World!" << std::endl;
  std::cout << "This is a test" << std::endl;
  fmt::print("I am using FMT new change");
  return 0;
}