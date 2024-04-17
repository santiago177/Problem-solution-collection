#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int main()
{
    bool guess[30];
    bool rev[30];
    int round, t1, t2, cont, bad, let;
    while(cin>>round && round != -1)
    {
        set<char> chk;
        memset(guess, false, 30);
        memset(rev, false, 30);
        cont = 0;
        bad = 0;
        string s1, s2;
        cin>>s1>>s2;
        t1 = s1.size();
        t2 = s2.size();
        for(int a = 0; a < t1; a++)
        {
            guess[s1[a]-'a'] = true;
            chk.insert(s1[a]);
        }
        for(int a = 0; a < t2; a++)
            rev[s2[a]-'a'] = true;
        for(int a = 0; a < 30; a++)
        {
            if(rev[a] && guess[a])
                cont++;
            if(!guess[a] && rev[a])
                bad++;
            if(cont == chk.size() || bad == 7)
                break;
            //cout<<"cont "<<cont<<" set size "<<chk.size()<< " bad "<<bad<<endl;
        }
        cout<<"Round "<<round<<endl;
        cont==chk.size()?cout<<"You win."<<endl:bad>=7?cout<<"You lose."<<endl:cout<<"You chickened out."<<endl;
    }
    return 0;
}
