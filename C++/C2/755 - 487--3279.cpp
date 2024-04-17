#include <iostream>
#include <cstdio>
#include <set>
#include <map>

using namespace std;
map<char, int> dic;

void init()
{
    dic['A'] = dic['B'] = dic['C'] = 2;
//    dic.put('A', 2);
//    dic.put('B', 2);
//    dic.put('C', 2);
    dic['D'] = dic['E'] = dic['F'] = 3;
//    dic.put('D', 3);
//    dic.put('E', 3);
//    dic.put('F', 3);
    dic['G'] = dic['H'] = dic['I'] = 4;
//    dic.put('G', 4);
//    dic.put('H', 4);
//    dic.put('I', 4);
    dic['J'] = dic['K'] = dic['L'] = 5;
//    dic.put('J', 5);
//    dic.put('K', 5);
//    dic.put('L', 5);
    dic['M'] = dic['N'] = dic['O'] = 6;
//    dic.put('M', 6);
//    dic.put('N', 6);
//    dic.put('O', 6);
    dic['P'] = dic['R'] = dic['S'] = 7;
//    dic.put('P', 7);
//    //dic.put('Q', 2);
//    dic.put('R', 7);
//    dic.put('S', 7);
    dic['T'] = dic['U'] = dic['V'] = 8;
//    dic.put('T', 8);
//    dic.put('U', 8);
//    dic.put('V', 8);
    dic['W'] = dic['X'] = dic['Y'] = 9;
//    dic.put('W', 9);
//    dic.put('X', 9);
//    dic.put('Y', 9);
}

int main()
{
    //freopen("755 - 487--3279.in", "r", stdin);
    init();
    int n;
    string s;
    char blank[1];
    scanf("%d", &n);
    fgets(blank, 0, stdin);
    for(int z = 0; z < n; z++)
    {
        if(z != 0)
            cout<<endl;
        bool noduplicates = true;
        int nums;
        map<string, int> times;
        set<string> list;
        cin>>nums;
        //cout<<"nums = "<<nums<<endl;
        for(int a = 0; a < nums; a++)
        {
            string aux = "", fin;
            cin>>s;
            for(int b = 0; b < s.size(); b++)
            {
                if(s[b] != '-')
                {
                    if(isdigit(s[b]))
                        aux += s[b];
                    else
                    {
                        aux += dic[s[b]]+'0';
                        //cout<<"dic[s[b]] = "<<dic[s[b]]<<endl;
                    }

                }
            }
            aux.insert(3, "-");
            //cout<<"aux = "<<aux<<endl;
            if(times.find(aux) == times.end())
                times[aux] = 1;
            else
                times[aux]++;
            list.insert(aux);
        }
        for(set<string>::iterator it = list.begin(); it!=list.end(); it++)
        {
            if(times[*it] > 1)
            {
                noduplicates = false;
                cout<<*it<<" "<<times[*it]<<endl;
            }
        }
        if(noduplicates)
            cout<<"No duplicates."<<endl;
    }
    return 0;
}


















