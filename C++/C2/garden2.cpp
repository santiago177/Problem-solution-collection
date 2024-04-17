#include <iostream>
#include <cstring>
#include <cstdio>
 
using namespace std;
 
struct WallInfo {
   bool horizontalWall, verticalWall;
};
 
int area;
WallInfo graph[102][102];
bool visited[102][102];
 
void floodFill(int x, int y) {
   if (x < 0 || x > 101 || y < 0 || y > 101)
      return;
   if (visited[y][x])
      return;
 
   visited[y][x] = true;
   --area;
 
   if (!graph[y][x].verticalWall)
      floodFill(x - 1, y);
   if (x < 101 && !graph[y][x + 1].verticalWall)
      floodFill(x + 1, y);
   if (!graph[y][x].horizontalWall)
      floodFill(x, y - 1);
   if (y < 101 && !graph[y + 1][x].horizontalWall)
      floodFill(x, y + 1);
}
 
int main(void) {
    freopen("garden.in", "r", stdin);
   int n;
   cin >> n;
 
   for(int i = 1; i <= n; ++i) {
 
      for(int j = 0; j < 102; ++j)
         for(int k = 0; k < 102; ++k)
            graph[j][k].horizontalWall = graph[j][k].verticalWall = false;
      memset(visited, 0, 102 * 102 * sizeof(bool));
      area = 102 * 102;
 
      int x, y, moves;
      cin >> x >> y >> moves;
 
      ++x;
      y = 100 - y;
 
      for(int j = 0; j < moves; ++j) {
         char direction;
         int steps;
         cin >> direction >> steps;
 
         if(direction == 'N') {
            for(int k = 1; k <= steps; ++k)
               graph[y - k][x].verticalWall = true;
            y -= steps;
         } else if(direction == 'S') {
            for(int k = 0; k < steps; ++k)
               graph[y + k][x].verticalWall = true;
            y += steps;
         } else if(direction == 'E') {
            for(int k = 0; k < steps; ++k)
               graph[y][x + k].horizontalWall = true;
            x += steps;
         } else {
            for(int k = 1; k <= steps; ++k)
               graph[y][x - k].horizontalWall = true;
            x -= steps;
         }
      }
      for(int a = 0; a < 102; a++)
      {
	  for(int b = 0; b < 102; b++)
	  {
	      if(graph[a][b].verticalWall && !graph[a][b].horizontalWall)
		  cout<<'|';
	      else if(graph[a][b].horizontalWall && !graph[a][b].verticalWall)
		  cout<<'_';
	      else if(graph[a][b].horizontalWall && graph[a][b].verticalWall)
		  cout<<'+';
	      else
		  cout<<'0';
	  }
	  cout<<endl;
      }
      floodFill(0, 0);
      cout << "Data Set " << i << ": " << area << " square feet.\n";
   }
 
   cout << "End of Output\n";
   return 0;
}