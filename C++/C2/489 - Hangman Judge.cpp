#include <iostream>
#include <cstdio>
#include <set>

using namespace std;
int main()
{
    int round;
    while(cin>>round && round != -1)
    {
        cout<<"Round "<<round<<endl;
        int bad = 0, correct = 0;
        string solution, answers;
        bool guess[256] = {0};
        set<char> letters;
        cin>>solution>>answers;
        for(int a = 0; a < solution.size(); a++)
            letters.insert(solution[a]);
        for(int a = 0; a < answers.size(); a++)
        {
            if(letters.find(answers[a])!=letters.end())
            {
                if(!guess[answers[a]])
                {
                    correct++;
                    guess[answers[a]] = true;
                }
            }
            else
            {
                if(!guess[answers[a]])
                {
                    bad++;
                    guess[answers[a]] = true;
                }
            }

            if(bad == 7 || correct == letters.size())
                break;
        }
        if(bad == 7)
            cout<<"You lose."<<endl;
        else if(correct == letters.size())
            cout<<"You win."<<endl;
        else
            cout<<"You chickened out."<<endl;


    }
    return 0;
}
