#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> liste(n);
    for(int a = 0; a < n; a++)
    {
	int p;
	scanf("%d", &p);
	liste[a] = p;
    }
    sort(liste.begin(), liste.end());
    for(int a = 0; a < n; a++)
	printf("%d\n", liste[a]);
    return 0;
}
