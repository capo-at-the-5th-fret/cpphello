#include "hello/hello.hpp"

auto main() -> int
{
  auto const result = name();

  return result == "hello" ? 0 : 1;
}
