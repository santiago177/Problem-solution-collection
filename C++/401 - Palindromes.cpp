#include <iostream>

using namespace std;

char reverses[60];

void init()
{
    for(int a = 0; a < 60; a++)
        reverses[a] = '0';
//    Character 	Reverse 	Character 	Reverse 	Character 	Reverse
//A 	A 	M 	M 	Y 	Y
//B 		N 		Z 	5
//C 		O 	O 	1 	1
//D 		P 		2 	S
//E 	3 	Q 		3 	E
//F 		R 		4
//G 		S 	2 	5 	Z
//H 	H 	T 	T 	6
//I 	I 	U 	U 	7
//J 	L 	V 	V 	8 	8
//K 		W 	W 	9
//L 	J 	X 	X
    reverses['A'-'0'] = 'A';
    reverses['E'-'0'] = '3';
    reverses['H'-'0'] = 'H';
    reverses['I'-'0'] = 'I';
    reverses['J'-'0'] = 'L';
    reverses['L'-'0'] = 'J';
    reverses['M'-'0'] = 'M';
    reverses['O'-'0'] = 'O';
    reverses['S'-'0'] = '2';
    reverses['T'-'0'] = 'T';
    reverses['U'-'0'] = 'U';
    reverses['V'-'0'] = 'V';
    reverses['W'-'0'] = 'W';
    reverses['X'-'0'] = 'X';
    reverses['Y'-'0'] = 'Y';
    reverses['Z'-'0'] = '5';
    reverses['1'-'0'] = '1';
    reverses['2'-'0'] = 'S';
    reverses['3'-'0'] = 'E';
    reverses['5'-'0'] = 'Z';
    reverses['8'-'0'] = '8';
}
bool isPalindrom;

int main()
{
    init();
    string n;
    while(cin>>n)
    {
        bool palindrom = true, mirrored = true;
        int s = n.size();
        for(int a = 0; a <= s/2 && (mirrored || palindrom); a++)
        {
            //cout<<"CHECK"<<endl;
            if(!(n[a] == n[s-a-1]))
                palindrom = false;
            if(!(reverses[n[a]-'0'] == n[s-a-1]))
            {
//                cout<<n[a]<<" "<<n[s-a-1]<<endl;
//                cout<<"NOT mirrored"<<endl;
                mirrored = false;
            }
        }
        if(palindrom && mirrored)
            cout<<n<<" -- is a mirrored palindrome."<<endl;
        else if(palindrom && !mirrored)
            cout<<n<<" -- is a regular palindrome."<<endl;
        else if(!palindrom && mirrored)
            cout<<n<<" -- is a mirrored string."<<endl;
        else
            cout<<n<<" -- is not a palindrome."<<endl;
        cout<<endl;
    }
    return 0;
}









