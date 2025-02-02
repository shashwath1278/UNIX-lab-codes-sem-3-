#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int i;
  if (argc <= 1) {
    cout << "No files to delete";
    cout << "usage: ./a.out FileName1 FileName2 …..\n";
    exit(1);
  }
  for (i = 1; i < argc; i++) {
    if (unlink(argv[i]) == -1)
      perror("Error in deleting...\n");
    else
      cout << "the file " << argv[i] << " is deleted...\n";
  }
  return 0;
}
