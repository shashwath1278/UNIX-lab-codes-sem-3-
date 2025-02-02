#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int n, fd1, fd2;
  char buf[10];
  if (argc != 3) {
    cout << "usage: ./a.out Source_FileName Destination_FileName\n";
    exit(1);
  }
  if ((fd1 = open(argv[1], O_RDONLY)) == -1) {
    cout << "Can't open file" << argv[1] << " for Reading\n";
    exit(0);
  }
  if ((fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 744)) == -1) {
    cout << "Can't open file " << argv[2] << " for Writing\n";
    exit(0);
  }
  while ((n = read(fd1, buf, 1)) > 0) {
    write(1, buf, n);    // write to terminal
    write(fd2, buf, n);  // write to file
  }
  close(fd1);
  close(fd2);
  return 0;
}
