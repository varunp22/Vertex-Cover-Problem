/*
Below code is for minimum vertex cover. This code also be used for determining the solution of below problem.

Let a company has to deploy minimum number of salesman in a particular area. Assume the vertices represents junction or end of a
road in that area. Connection between two nodes represents road in the area. As we get the value of minimum vertex cover, it 
actually represents the minimum number of salesman required to cover up the colony.
*/

#include<bits/stdc++.h>
 
using namespace std;
 
bool graph[1001][1001];
bool vis[1001][1001];
 
int i,j,k,v;
int n,e,x,y;
 
bool isVertexCover(int sz)
{
    int c,r,cnt=0;
    int set = (1 << sz) - 1;
    int limit = (1 << n);
    while (set < limit)
    {
        memset(vis,0,sizeof(vis));
        cnt = 0;
        for (j = 1, v = 1 ; j < limit ; j = j << 1, v++)
        {
            if (set & j)
            {
                for (k = 0 ; k <= n-1 ; k++)
                {
                    if (graph[v][k] && !vis[v][k])
                    {
                        vis[v][k] = 1;
                        vis[k][v] = 1;
                        cnt++;
                    }
                }
            }
        }
        if (cnt == e)
            return true;
        c = set & -set;
        r = set + c;
        set = (((r^set) >> 2) / c) | r;
    }
    return false;
}
 
int main()
{
	cout<<"Enter number of vertices:";   //vertices represents number of nodes or junction of roads
	cin>>n;
	cout<<"\nEnter number of Edges:";   //edges represents connection between two nodes
	cin>>e;
	for(i=0;i<e;i++)
	{
		cout<<"Enter the end-points of edge "<<i+1<<":";
		cin>>x>>y;
		x--; y--;
		graph[x][y]=1;
		graph[y][x]=1;
	}
	int num=n;
	int min;
	for(int z=0;z<n-1;z++)
	{
    	if(isVertexCover(num))
    	    min=num;
    	num--;
	}
	cout<<"Minimum vertex cover achieved for "<<min<<" vertices";   //value of minimum vertex cover is the number of minimum salesman
	return 0;
}