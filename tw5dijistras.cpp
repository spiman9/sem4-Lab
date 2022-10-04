#include<bits/stdc++.h>
using namespace std;
#define inf 999

void Dij(int n , int v , int cost[20][20] , int dist[20])
{
    int flag[20] = {0};
    for(int w = 1 ; w<=n ; w++)
    {
        dist[w] = cost[v][w];
        flag[w] = 0;
    }

    int count = 1;
    while(count < n)
    {
        int min = inf;
        int u;
        for(int w = 1 ; w<=n ;w++)
        {
            if(dist[w] < min && flag[w] == 0)
            {
                u = w;
                min = dist[w];
            }
        }

        flag[u] = 1;
        count++;
        for(int w =1 ; w<=n ; w++)
        {
            if((dist[u] + cost[u][w]) < dist[w] && flag[w] == 0)
            {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the Number of Vertices : ";
    cin >> n;
    cout << "Enter in the Cost Matrix\n";
    int dist[20];
    int cost[20][20];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> cost[i][j];
            if(cost[i][j] == 0)
                cost[i][j] = inf;
        }
    }

    cout << "Enter the Source : ";
    int v;
    cin >> v;

    Dij(n , v , cost , dist);

    cout << "Shortest paths are\n";
    for(int i=1;i<=n;i++)
    {
        if(i!=v)
        {
            printf("%d to %d --------> %d\n" , v , i , dist[i]);
        }
    }
}