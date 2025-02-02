#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    cout << "usage: ./a.out Source_FileName Link_FileName\n";
    exit(1);
  }
  if ((link(argv[1], argv[2])) == -1)
    perror("Link eror\n");
  else
    unlink(argv[1]);  // deletes first file
  return 0;
}
