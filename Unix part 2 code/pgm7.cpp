#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main() {
  pid_t pid;
  if ((pid = fork()) == -1) {
    perror("Fork Error");
    exit(0);
  }
  if (pid == 0) /* child */
  {
    sleep(5);
    cout << "\n Child :" << getpid() << "\tOrphan's Parent :" << getppid()
         << endl;
  }
  if (pid > 0) /* parent */
  {
    cout << "\n Original Parent:" << getpid() << endl;
    exit(0);
  }
  return 0;
}
