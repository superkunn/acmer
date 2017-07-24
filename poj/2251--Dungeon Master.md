[返回](https://github.com/superkunn/acmer)
## Dungeon Master
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 33998		Accepted: 12990
Description

You are trapped in a 3D dungeon and need to find the quickest way out! The dungeon is composed of unit cubes which may or may not be filled with rock. It takes one minute to move one unit north, south, east, west, up or down. You cannot move diagonally and the maze is surrounded by solid rock on all sides. 

Is an escape possible? If yes, how long will it take? 
Input

The input consists of a number of dungeons. Each dungeon description starts with a line containing three integers L, R and C (all limited to 30 in size). 
L is the number of levels making up the dungeon. 
R and C are the number of rows and columns making up the plan of each level. 
Then there will follow L blocks of R lines each containing C characters. Each character describes one cell of the dungeon. A cell full of rock is indicated by a '#' and empty cells are represented by a '.'. Your starting position is indicated by 'S' and the exit by the letter 'E'. There's a single blank line after each level. Input is terminated by three zeroes for L, R and C.
Output

Each maze generates one line of output. If it is possible to reach the exit, print a line of the form 
Escaped in x minute(s).

where x is replaced by the shortest time it takes to escape. 
If it is not possible to escape, print the line 
Trapped!
Sample Input

3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0
Sample Output

Escaped in 11 minute(s).
Trapped!

```c++
#include <iostream>
#include <cstdio>
using namespace std;

struct gg
{
    char fu;
    int bu;
};

gg g[35][35][35];
int ex,ey,ez;

struct biao
{
    int xx;
    int yy;
    int zz;
    int step;
};

biao dui[100000];
int head=0,tail=1;
int shu=0;



void bfs(int x,int y,int z)
{


    if((g[x+1][y][z].fu=='.'||g[x+1][y][z].fu=='E')&&g[x+1][y][z].bu==0)
    {
        if(g[x+1][y][z].fu=='E')
        {

            cout<<"Escaped in "<<dui[head].step+1<<" minute(s)."<<endl;
            head=tail-1;
            shu=1;
            return;

        }
        dui[tail].xx=x+1;
        dui[tail].yy=y;
        dui[tail].zz=z;
        dui[tail].step=dui[head].step+1;
        tail++;
        g[x+1][y][z].bu=1;

    }
    if((g[x-1][y][z].fu=='.'||g[x-1][y][z].fu=='E')&&g[x-1][y][z].bu==0)
    {
        if(g[x-1][y][z].fu=='E')
        {

            cout<<"Escaped in "<<dui[head].step+1<<" minute(s)."<<endl;
            head=tail-1;
            shu=1;
            return;

        }
        dui[tail].xx=x-1;
        dui[tail].yy=y;
        dui[tail].zz=z;
        dui[tail].step=dui[head].step+1;
        tail++;
        g[x-1][y][z].bu=1;
    }
    if((g[x][y+1][z].fu=='.'||g[x][y+1][z].fu=='E')&&g[x][y+1][z].bu==0)
    {
        if(g[x][y+1][z].fu=='E')
        {

            cout<<"Escaped in "<<dui[head].step+1<<" minute(s)."<<endl;
            head=tail-1;
            shu=1;
            return;

        }
        dui[tail].xx=x;
        dui[tail].yy=y+1;
        dui[tail].zz=z;
        dui[tail].step=dui[head].step+1;
        tail++;
        g[x][y+1][z].bu=1;
    }
    if((g[x][y-1][z].fu=='.'||g[x][y-1][z].fu=='E')&&g[x][y-1][z].bu==0)
    {
        if(g[x][y-1][z].fu=='E')
        {

            cout<<"Escaped in "<<dui[head].step+1<<" minute(s)."<<endl;
            head=tail-1;
            shu=1;
            return;

        }
        dui[tail].xx=x;
        dui[tail].yy=y-1;
        dui[tail].zz=z;
        dui[tail].step=dui[head].step+1;
        tail++;
        g[x][y-1][z].bu=1;
    }
    if((g[x][y][z+1].fu=='.'||g[x][y][z+1].fu=='E')&&g[x][y][z+1].bu==0)
    {
        if(g[x][y][z+1].fu=='E')
        {

            cout<<"Escaped in "<<dui[head].step+1<<" minute(s)."<<endl;
            head=tail-1;
            shu=1;
            return;

        }
        dui[tail].xx=x;
        dui[tail].yy=y;
        dui[tail].zz=z+1;
        dui[tail].step=dui[head].step+1;
        tail++;
        g[x][y][z+1].bu=1;
    }
    if((g[x][y][z-1].fu=='.'||g[x][y][z-1].fu=='E')&&g[x][y][z-1].bu==0)
    {
        if(g[x][y][z-1].fu=='E')
        {

            cout<<"Escaped in "<<dui[head].step+1<<" minute(s)."<<endl;
            head=tail-1;
            shu=1;
            return;

        }
        dui[tail].xx=x;
        dui[tail].yy=y;
        dui[tail].zz=z-1;
        dui[tail].step=dui[head].step+1;
        tail++;
        g[x][y][z-1].bu=1;
    }

}

int main()
{


    int x,y,z;
    while(cin>>x>>y>>z&&x&&y&&z)
    {
        int i,j,k;

        for(i=1;i<=x;i++)
        {
            for(j=1;j<=y;j++)
            {
                for(k=1;k<=z;k++)
                {
                    cin>>g[i][j][k].fu;
                    g[i][j][k].bu=0;

                    if(g[i][j][k].fu=='S')
                    {
                        dui[head].xx=i;
                        dui[head].yy=j;
                        dui[head].zz=k;
                        dui[head].step=0;

                    }
                    if(g[i][j][k].fu=='E')
                    {
                        ex=i;
                        ey=j;
                        ez=k;
                    }
                }
            }
        }//put in


        while(head!=tail)
        {

            bfs(dui[head].xx,dui[head].yy,dui[head].zz);
            head++;
        }

        if(shu==0)
        {
            cout<<"Trapped!"<<endl;
        }


        head=0;
        tail=1;
        shu=0;

        for(i=0;i<100000;i++)
        {
            dui[i].step=0;
        }








    }//end while

    return 0;
}
```
[返回](https://github.com/superkunn/acmer)
