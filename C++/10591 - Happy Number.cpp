#include <iostream>

using namespace std;

int main()
{
    long long n, c;
    cin>>c;
    for(int z = 0; z < c; z++)
    {
        cin>>n;
        bool happy = true;
        long long num = n;
        bool rev[811];
        for(int a = 1; a < 811; a++)
            rev[a] = false;
        while(1)
        {
            long long cont = 0;
            while(num!=0)
            {
                cont += (num%10)*(num%10);
                //cout<<"mod "<<num%10*num%10<<endl;
                num/=10;
            }
            //cout<<cont<<endl;
            //system("pause");
            if(rev[cont])
            {
                happy = false;
                break;
            }
            else if(cont == 1)
                break;
            rev[cont] = true;
            num = cont;
        }
//        Case #p: N is a Happy number.
//
//Case #p: N is an Unhappy number.
        if(happy)
            cout<<"Case #"<<z+1<<": "<<n<<" is a Happy number."<<endl;
        else
            cout<<"Case #"<<z+1<<": "<<n<<" is an Unhappy number."<<endl;
    }
    return 0;
}








