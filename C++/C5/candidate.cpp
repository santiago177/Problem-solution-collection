#include <bits/stdc++.h>

using namespace std;

int min_i, max_i;

void print(vector<int> v)
{
    cout<<"print ";
    for(int i=0; i<v.size(); i++)
	cout<<v[i]<<" ";
    cout<<endl;
}

bool is_valid(vector<int> &indexes, vector<string> &table)
{
    set<string> entries;
    for(int i=0; i<table.size(); i++)
    {
	string s="";
	for(int j=0; j<indexes.size(); j++)
	    s += table[i][indexes[j]];
	if(entries.count(s) != 0)
	    return false;
    }
    return true;
}

bool is_candidate(vector<int> indexes, vector<string> &table)
{
    bool valid = true;
    if(indexes.size()==1)
	return is_valid(indexes, table);
    cout<<"in ";
    print(indexes);
    for(int i=0; i<indexes.size(); i++)
    {
	vector<int> neu = indexes;
	neu.erase(indexes.begin()+i);
	cout<<"neu ";
	print(neu);
	cout<<"here"<<endl;
	if(is_candidate(neu, table))
	    valid = false;
    }
    if(valid)
	valid = is_valid(indexes, table);
    if(valid)
    {
	if(indexes.size() < min_i)
	    min_i = indexes.size();
	if(indexes.size() > max_i)
	    max_i = indexes.size();
    }
    cout<<"return "<<valid<<endl;
    return valid;
}

int main()
{
    min_i = 1<<30;
    max_i = 0;
    int n, m;
    cin>>n>>m;
    vector<string> table(n);
    for(int i=0; i<n; i++)
	cin>>table[i];
    
    vector<int> indexes(m);
    for(int i=0; i<m; i++)
	indexes[i]=i;
    cout<<"first"<<endl;
    print(indexes);
    is_candidate(indexes, table);
    cout<<min_i<<" "<<max_i<<endl;
    return 0;
}
