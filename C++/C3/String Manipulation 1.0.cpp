#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int k, n;
    bool gemacht;
    string s;
    cin>>k;
    cin>>s;
    cin>>n;
    vector<string> strs(k);
    for(int a = 0; a < k; a++)
	strs[a] = s;
    for(int h = 0; h < n; h++)
    {
	gemacht = false;
	int p, cont = 1;
	char c;
	cin>>p>>c;
//	cout<<"in"<<endl;
	for(int a = 0; a < k; a++)
	{
	    for(int b = 0; b < strs[a].size() && !gemacht; b++)
	    {
		//cout<<"for2"<<endl;
		if(strs[a][b] == c && p == cont)
		{
		    //cout<<"in2"<<endl;
		    strs[a].replace(b, 1, "");
		    //cout<<"current ";
		    /*for(int g = 0; g < k; g++)
			cout<<strs[g];
		    cout<<endl;*/
		    gemacht = true;
		    break;
		}
		else if(strs[a][b] == c && cont < p)
		    cont++;
	    }
	    if(gemacht)
		break;
	}
    }
    for(int a = 0; a < k; a++)
    {
	cout<<strs[a];
    }
    return 0;
}