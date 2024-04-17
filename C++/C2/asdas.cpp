    #include<iostream>
    #include<algorithm>
    #include<math.h>
    using namespace std;

    int main(){
       int a,b;
       float t;
       bool set;
       while(cin>>a>>b){
          set=false;
          t=a/float(b);
          if(t>=0){
             cout<<'['<<a/b<<';';
             a=a-a/b*b;
             cout<<a<<endl;
          }
          else{
             cout<<'['<<a/b-1<<';';
             a=fabs(b)-(fabs(a)-fabs(a/b*b));
             b=fabs(b);
          }
          while(a!=0){
             swap(a,b);
             cout<<a/b<<',';
             a=a-a/b*b;
             set=true;
          }
          if(set)
             cout<<"\b]\n";
          else
             cout<<"]\n";
       }
       return 0;
    }
