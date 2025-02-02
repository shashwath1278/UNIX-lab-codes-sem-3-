#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main() {
  pid_t pid;
  int status;
  if ((pid = fork()) == -1) {
    perror("Fork Error");
    return 0;
  }
  if (pid == 0) { /* child */
    cout << "\nChild :" << getpid()
         << " Waiting for parent to retrieve its exit status\n";
    exit(0);
  }
  if (pid > 0) /* parent */
  {
    wait(&status);
    cout << "\nParent:" << getpid();
    system("ps u");
  }
  return (0);
}
