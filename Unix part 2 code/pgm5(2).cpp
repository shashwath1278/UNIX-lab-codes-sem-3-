#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>
using namespace std;
int main() {
  pid_t pid;
  cout << "\n Original Process:" << getpid() << "\tParent Process:" << getppid()
       << endl;
  if ((pid = vfork()) == -1) {
    perror("Fork Error");
    exit(0);
  }
  if (pid == 0) { /* child */
    cout << "\n Child Process:" << getpid() << "\tParent Process:" << getppid()
         << endl;
  }
  if (pid > 0) { /* parent */
    cout << "\n Original Process:" << getpid()
         << "\tParent Process:" << getppid() << endl;
  }
  cout << "\n end of Main\n";
  return 0;
}
