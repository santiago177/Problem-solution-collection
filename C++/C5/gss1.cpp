#include <iostream>
#include <vector>

using namespace std;

vector<void *> dynamic;

int max3(int a, int b, int c)
{
    if(a > b && a > c)
	return a;
    if(b > c)
	return b;
    return c;
}

class node
{
    public:
	node *left, *right;
	long long sum, low, high, highest;
	node(int * array, int low, int high)
	{
	    this->low = low; this->high = high;
	    if(low == high)
	    {
		sum = array[low];
		highest = sum;
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
		sum = left -> sum + right -> sum;
		highest = max3(sum, left -> highest, right -> highest); 
	    }
	}
};


int get(node *n, int low, int high)
{
    if(n -> low == low && n-> high == high)
	return n -> highest;
    else
    {
	if(high <= n -> left -> high)
	    return get(n -> left, low, high);
	if(low >= n -> right -> low)
	    return get(n -> right, low, high);
	long long s1 = get(n -> left, low, n -> left -> high);
	long long s2 = get(n -> right, n -> right -> low, high);
	if(s1 > s2)
	    return s1;
	else
	    return s2;
    }
}

void print(node *n)
{
    int low = n -> low, high = n -> high;
    if(low == high)
	cout<<"pos "<<low<<" highest "<<n -> highest<<" sum "<<n -> sum<<endl;
    else
    {
	print(n -> left);
	print(n -> right);
	cout<<"range "<<low<<" "<<high<<" highest "<< n -> highest<<" sum "<< n -> sum<<endl;
    }
}


int main()
{
    //int array[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int array[5] = {3, -10, 100, -2, 20}; 
    node n(array, 0, 4);

    cout<<get(&n, 0, 4)<<endl;
    print(&n);
    return 0;
}

