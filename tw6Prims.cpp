#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , cost[20][20] , ne = 1 , min , mincost=0 , a , b , u , v  , visited[20] = {0};
    cout << "Enter the Number of Vertices : ";
    cin >> n;
    cout << "Enter the costs in cost matrix\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> cost[i][j];
            if(cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }
    visited[1] = 1;

    while(ne < n)
    {
        min = 999;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(cost[i][j] < min  && visited[i]!=0)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
            
        }

        if(visited[a] == 0 || visited[b] == 0)
        {
            mincost+=cost[a][b];
            printf("%d Edge : (%d , %d) ----> %d\n" , ne++ , a, b , min);
            visited[b] = 1;
        }
        cost[a][b] = 999;
        cost[b][a] = 999;
    }
    cout << "The Minimum cost is : " << mincost << endl;

    
}


 /* Let us create the following graph
        2 3
    (0)--(1)--(2)
    | / \ |
    6| 8/ \5 |7
    | /     \ |
    (3)-------(4)
            9         */

// Enter the Number of Vertices : 5
// Enter the costs in cost matrix
// 0 2 0 6 0 
// 2 0 3 8 5
// 0 3 0 0 7
// 6 8 0 0 9
// 0 5 7 9 0
// 1 Edge : (1 , 2) ----> 2
// 2 Edge : (2 , 3) ----> 3
// 3 Edge : (2 , 5) ----> 5
// 4 Edge : (1 , 4) ----> 6
// The Minimum cost is : 16