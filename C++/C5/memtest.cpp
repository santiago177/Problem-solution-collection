#include <iostream>

using namespace std;

int main() {

    int ** array;
    array = new int * [4];
    for(int i=0; i<5; i++) {
	array[i] = new int[i];
	for(int j=0; j<i; j++)
	    array[i][j]=j;

    }
    for(int i=0; i<5; i++) {
	for(int j=0; j<i; j++) {
	    cout<<array[i][j]<<" ";
	}
	cout<<endl;
    }
    delete [] array;
    return 0;
}
