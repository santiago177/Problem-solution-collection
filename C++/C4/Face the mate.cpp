#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double PI = acos(-1);

int main()
{
    int n;
    scanf("%d", &n);
    for(int z = 0; z < n; z++)
    {
	int x1, y1, u1, v1, x2, y2, u2, v2;
	scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &u1, &v1, &x2, &y2, &u2, &v2);
	int jx, jy, kx, ky, jkx, jky, kjx, kjy, product1, product2;
	jx = u1 - x1; jy = v1 - y1; kx = u2 - x2; ky = v2 - y2;
	jkx = x2 - x1; jky = y2 - y1; kjx = x1 - x2; kjy = y1 - y2;
	//printf("%d %d %d %d %d %d\n", jx, jy, kx, ky, jkx, jky);
	product1 = jx * jkx + jy * jky;
	product2 = kx * kjx + ky * kjy;
	double nj, nk, njk;
	double theta, alpha;
	nj = sqrt(jx*jx + jy * jy);
	nk = sqrt(kx*kx + ky * ky);
	njk = sqrt(jkx*jkx + jky * jky);
	theta = acos(product1 / (nj * njk));
	alpha = acos(product2 / (nk * njk));
	if(theta > PI)
	    theta -= PI;
	if(alpha > PI)
	    alpha -= PI;
//	printf("%.12lf %.12lf %d %d\n", theta, alpha, product1, product2);
	if(abs(theta - alpha) < 0.0000000000001)
	    printf("0\n");
	else if(theta > alpha)
	    printf("Heroine\n");
	else
	    printf("Hero\n");
    }
    return 0;
}
