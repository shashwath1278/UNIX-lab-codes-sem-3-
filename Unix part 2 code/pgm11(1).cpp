#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

using namespace std;
void handler(int signo) {
  cout << "\nsignal handlar : catched signal num is =>" << signo << endl;
  exit(0);
}
int main() {
  signal(SIGINT, handler);
  while (1) cout << "hello \t ";
}
