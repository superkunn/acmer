[返回](https://github.com/superkunn/acmer)
## Oil Deposits

Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 17675		Accepted: 9380
Description

The GeoSurvComp geologic survey company is responsible for detecting underground oil deposits. GeoSurvComp works with one large rectangular region of land at a time, and creates a grid that divides the land into numerous square plots. It then analyzes each plot separately, using sensing equipment to determine whether or not the plot contains oil. A plot containing oil is called a pocket. If two pockets are adjacent, then they are part of the same oil deposit. Oil deposits can be quite large and may contain numerous pockets. Your job is to determine how many different oil deposits are contained in a grid.
Input

The input contains one or more grids. Each grid begins with a line containing m and n, the number of rows and columns in the grid, separated by a single space. If m = 0 it signals the end of the input; otherwise 1 <= m <= 100 and 1 <= n <= 100. Following this are m lines of n characters each (not counting the end-of-line characters). Each character corresponds to one plot, and is either '*', representing the absence of oil, or '@', representing an oil pocket. 

Output

are adjacent horizontally, vertically, or diagonally. An oil deposit will not contain more than 100 pockets.
```
Sample Input

1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5 
****@
*@@*@
*@**@
@@@*@
@@**@
0 0

Sample Output

0
1
2
2
```

```c++
#include <iostream>
#include <cstdio>
using namespace std;



char g[105][105];



void dfs(int x,int y)
{
   if(g[x][y]=='@')
   {
       g[x][y]='1';

       if(g[x][y+1]=='@')
        dfs(x,y+1);
       if(g[x+1][y+1]=='@')
        dfs(x+1,y+1);
       if(g[x+1][y]=='@')
        dfs(x+1,y);
       if(g[x+1][y-1]=='@')
        dfs(x+1,y-1);
       if(g[x][y-1]=='@')
        dfs(x,y-1);
       if(g[x-1][y-1]=='@')
        dfs(x-1,y-1);
       if(g[x-1][y]=='@')
        dfs(x-1,y);
       if(g[x-1][y+1]=='@')
        dfs(x-1,y+1);

   }
}

int main()
{

    int m,n;
    while(cin>>m>>n&&m&&n)
    {
        int i,j;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                cin>>g[i][j];
            }
        }

        int shu=0;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(g[i][j]=='@')
                {
                    dfs(i,j);
                    shu++;
                }

            }

        }


        cout<<shu<<endl;



    }



    return 0;
}
```
[返回](https://github.com/superkunn/acmer)
