#include <signal.h>
#include <unistd.h>
#include <iostream>

using namespace std;
int main() {
  signal(SIGINT, SIG_DFL);
  while (1) cout << "hello\t";
}
