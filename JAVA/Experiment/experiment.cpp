#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char * argv[]) {
    printf("argc %d\n", argc);
    for(int i = 0; i < argc; i++) {
        printf("arg %s\n", argv[i]);
    }
    return 0;
}
