#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>

using namespace std;
int status;
int system(const char *cmd) {
  pid_t pid;
  if (cmd == NULL) return (1); /* always a command processor with Unix */
  if ((pid = fork()) < 0) {
    status = -1;         /* probably out of processes */
  } else if (pid == 0) { /* child */
    execl("/bin/sh", "sh", "-c", cmd, (char *)0);
    _exit(127); /* execl error */
  } else {      /* parent */
    while (waitpid(pid, &status, 0) < 0)
      if (errno != EINTR) {
        status = -1; /* error other than EINTR from waitpid() */
        break;
      }
  }
  return (status);
}
int main(void) {
  if ((status = system("date; exit 0")) < 0) perror("system error");
  if ((status = system("daaate")) < 0) perror("system error");
  if ((status = system("who; exit 44")) < 0) perror("system error");
  exit(0);
}
