#include <iostream>
#include <vector>

using namespace std;

vector<void *> dynamic;


class node
{
    public:
	node *left, *right;
	long long num, square, low, high;
	node(int * array, int low, int high)
	{
	    this->low = low; this->high = high;
	    if(low == high)
	    {
		num = array[low];
		square = num*num;
		left = NULL;
		right = NULL;
	    }
	    else
	    {
		//cout<<"low "<<low<<" (low + high)/2 "<< (low + high)/2<<" (low + high)/2 + 1 "<<(low + high)/2 + 1<<" high "<<high<<endl;
		node *n1 = new node(array, low, (low + high)/2);  
		node *n2 = new node(array, (low + high)/2 + 1, high);
		dynamic.push_back(n1);
		dynamic.push_back(n2);
		left = n1;
		right = n2;
		square = left -> square + right -> square;
		num = 0;
	    }
	}
};

long long get(node *n, int low, int high) // funciona
{
    if(n -> low == low && n-> high == high)
	return n -> square;
    else
    {
	if(high <= n -> left -> high)
	    return get(n -> left, low, high);
	if(low >= n -> right -> low)
	    return get(n -> right, low, high);

	long long s1 = get(n -> left, low, n -> left -> high);
	long long s2 = get(n -> right, n -> right -> low, high);
	return s1 + s2;
    }
}

void add(node *n, int num, int low, int high)
{
    if(low == high)
    {
	n -> num += num;
	n -> square =  n -> num * n -> num;
    }
    else
    {
	if(high <= n -> left -> high)
	    add(n -> left, num, low, high);
	else if(low >= n -> right -> low)
	    add(n -> right, num, low, high);
	else
	{
	    add(n -> left, num, low, n -> left -> high);
	    add(n -> right, num, n -> right -> low, high);
	}
	//set(n -> left, num, low, (low + high)/2);
	//set(n -> right, num, (low + high)/2 + 1, high);
	n -> square = (n -> left) -> square + (n -> right) -> square;
    }
}

void set(node *n, int num, int low, int high)
{
    if(n -> low == low && n -> high == high && low == high)
    {
	//cout<<"at pos "<<low<<" set "<<num<<endl;
	n -> num = num;
	n -> square = n -> num * n -> num;
    }
    else
    {
	if(high <= n -> left -> high)
	    set(n -> left, num, low, high);
	else if(low >= n -> right -> low)
	    set(n -> right, num, low, high);
	else
	{
	    set(n -> left, num, low, n -> left -> high);
	    set(n -> right, num, n -> right -> low, high);
	}
	//set(n -> left, num, low, (low + high)/2);
	//set(n -> right, num, (low + high)/2 + 1, high);
	n -> square = (n -> left) -> square + (n -> right) -> square;
    }
}

void print(node *n)
{
    int low = n -> low, high = n -> high;
    if(low == high)
	cout<<"pos "<<low<<" pow "<<n -> square<<" num "<<n -> num<<endl;
    else
    {
	print(n -> left);
	print(n -> right);
	cout<<"range "<<low<<" "<<high<<" value "<< n-> square<<endl;
    }
}

int main()
{
    /*int array[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    node n(array, 0, 7);
    cout<<get(&n, 0, 7)<<endl;
    cout<<get(&n, 4, 6)<<endl;
    add(&n, 1, 0, 3);*/
    //set(&n, 1, 2, 3);
    //add(&n, 1, 2, 3);
    //print(&n);
    int cases;
    int array[100000];
    cin>>cases;
    for(int z = 0; z < cases; z++)
    {
	dynamic.clear();
	cout<<"Case "<<z+1<<":\n";
	int N, Q;
	cin>>N>>Q;
	for(int b = 0; b < N; b++)
	    cin>>array[b];
	node n(array, 0, N-1);
	for(int b = 0; b < Q; b++)
	{
	    int key, st, nd, x;
	    cin>>key;
	    if(key == 2)
	    {
		cin>>st>>nd;
		long long ans = get(&n, st-1, nd-1);
		cout<<ans<<endl;

	    }
	    else
	    {
		cin>>st>>nd>>x;
		if(key == 1)
		    add(&n, x, st-1, nd-1);
		else
		    set(&n, x, st-1, nd-1);
	    }
	}
	for(int a = 0; a < dynamic.size(); a++)
	    delete (node*)dynamic[a];
    }
    return 0;
}
