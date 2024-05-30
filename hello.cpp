#include <iostream>
#include "hello.h"

int hello() {
  std::cout << "Hello SonarLint!\n";

  /* A simple broken rule that Sonar should detect
   * "goto" should jump to labels declared later in the same function
   *  https://rules.sonarsource.com/cpp/RSPEC-999/
   */
  volatile int j = 0;
L1:
  ++j;
  if (10 == j) {
    goto L2; // forward jump ignored
  }
  // ...
  goto L1; // Noncompliant
L2:
  return ++j;
}