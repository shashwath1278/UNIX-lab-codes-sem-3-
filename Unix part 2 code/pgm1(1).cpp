#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "usage: ./a.out Source_FileName Link_FileName\n";
        exit(0);
    }

    if (link(argv[1], argv[2]) == -1)
        perror("link error");
    else
        cout << "Link has been created with the name " << argv[2] << endl;

    return 0;
}

