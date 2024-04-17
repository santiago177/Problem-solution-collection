#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    //freopen("10361 - Automatic Poetry.in", "r", stdin);
    //freopen("10361 - Automatic Poetry.out", "w", stdout);
    int n;
    vector<string> fin;
    cin>>n;
    cin.ignore();
    for(int z = 0; z < n; z++)
    {

        vector<string> v;
        string s1, s2, con, replace;
        int count = 0;
        getline(cin, s1);
        getline(cin, s2);
        bool open = false;
        for(int a = 0; a < s1.size(); a++)
        {
//            if(z == 2)
//                cout<<s1[a]<<endl;
            if(s1[a] == '<')
            {
                open = true;
                if(count > 0)
                {
                    v.push_back(con);
                    //cout<<con<<" pushed"<<endl;
                }
                con = "";
            }
            else if(s1[a] == '>')
            {
                v.push_back(con);
                //cout<<con<<" pushed"<<endl;
                count++;
                con = "";
            }
            else if(open)
            {
                con += s1[a];
            }
        }
        v.push_back(con);
        //cout<<con<<" pushed"<<endl;
        con = "";
        for(int a = 0; a < s1.size(); a++)
        {
            if(s1[a] != '>' && s1[a] != '<')
                con += s1[a];
        }
        fin.push_back(con);
        con = "";
        open = false;
        replace = v[2]+v[1]+v[0]+v[3];
        //cout<<"replace = "<<replace<<endl;
        //s4s3s2s5
        for(int a = 0; a < s2.size(); a++)
        {
//            if(z == 2)
//                cout<<s2[a]<<endl;
            if(s2[a] == '.' && a < s2.size()-2)
            {
                if(s2[a+1] == '.' && s2[a+2] == '.')
                {
                    con += replace;
                    a += 2;
                    continue;
                }
                else
                {
                    con += s2[a];
                }
            }
            else
                con += s2[a];
        }
        fin.push_back(con);

    }
    for(int a = 0; a < fin.size(); a++)
    {
        cout<<fin[a]<<endl;
    }
    return 0;
}















