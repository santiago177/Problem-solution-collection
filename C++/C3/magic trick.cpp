#include <iostream>
#include <map>


using namespace std;

map<char, int> m;
int inv[13];

void bmap()
{
    m['1'] = 1;
    m['2'] = 2;
    m['3'] = 3;
    m['4'] = 4;
    m['5'] = 5;
    m['6'] = 6;
    m['7'] = 7;
    m['8'] = 8;
    m['9'] = 9;
    m['T'] = 10;
    m['J'] = 11;
    m['Q'] = 12;
    m['K'] = 13;
    inv[0] = '1';
    inv[1] = '2';
    inv[2] = '3';
    inv[3] = '4';
    inv[4] = '5';
    inv[5] = '6';
    inv[6] = '7';
    inv[7] = '8';
    inv[8] = '9';
    inv[9] = 'T';
    inv[10] = 'J';
    inv[11] = 'Q';
    inv[12] = 'K';
}


// regresa si el de la izquierda es mayor que el de la derecha
// Diese Funktion gebt uns zurueck, wenn der linke Wert groesser als der rechte ist
bool comp(string s, string d)
{
    int t, y;
    t = m[s[0]];
    y = m[d[0]];
    if(s[1] == d[1])
    {
	if(t > y)
	    return true;
	return false;
    }
    else if(s[1] == 'S')
	return true;
    else if(s[1] == 'D')
    {
	if(d[1] == 'S')
	    return false;
	return true;
    }
    else if(s[1] == 'C')
    {
	if(d[1] == 'S' || d[1] == 'D')
	    return false;
	return true;
    }
    return false;
}

int pos(string s1, string s2, string s3)
{
    if(comp(s2, s1) && comp(s3, s2))
	return 1;
    else if(comp(s2, s3) && comp(s3, s1))
	return 2;
    else if(comp(s3, s1) && comp(s1, s2))
	return 3;
    else if(comp(s2, s1) && comp(s1, s3))
	return 4;
    else if(comp(s1, s3) && comp(s3, s2))
	return 5;
    return 6;
}

int main()
{
    bmap();
    int n;
    cin>>n;
    for(int a = 0; a < n; a++)
    {
	char type, gesicht;
	string s1, s2, s3, s4;
	cin>>s1>>s2>>s3>>s4;
	type = s1[1];
	//cout<<m[s1[0]]<<" "<<pos(s2, s3, s4)<<endl;
	gesicht = inv[(m[s1[0]]+pos(s2, s3, s4)-1)%13];
	cout<<gesicht<<type<<endl;
    
    }
    return 0;
}
