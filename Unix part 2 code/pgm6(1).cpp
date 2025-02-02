#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(void) {
  pid_t pid;
  if ((pid = fork()) == -1) {
    perror("Fork Error");
    exit(0);
  }
  if (pid == 0) /* child */
  {
    cout << "\nChild :" << getpid()
         << " Waiting for parent to retrieve its exit status\n";
    exit(0);
  } /* parent */
  if (pid > 0) {
    sleep(5);
    cout << "\nParent:" << getpid();
    system("ps u");
  }
  return (0);
}
