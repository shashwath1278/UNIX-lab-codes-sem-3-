#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int fd, n, skval;
  char c;
  if (argc != 2) {
    cout << "usage: ./a.out FileName\n";
    exit(1);
  }
  if ((fd = open(argv[1], O_RDONLY)) == -1) {
    cout << "Can't open file " << argv[1] << " for Reading\n";
    exit(0);
  }
  while ((n = read(fd, &c, 1)) == 1) {
    cout << "\nChar: " << c;
    skval = lseek(fd, 5, 1);
    cout << "\nNew seek value is:" << skval;
  }
  cout << endl;
  exit(0);
}
