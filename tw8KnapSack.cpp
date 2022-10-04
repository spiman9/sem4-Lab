#include<bits/stdc++.h>
using namespace std;

int V[100][100] , res[100] = {0},ct = 0;


int max(int a , int b)
{
    return a>b ? a : b;
}
int KnapSack(int W , int wt[] , int val[] , int n)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if( i == 0 || j == 0)
            {
                V[i][j] = 0;
            }
            else if(wt[i-1] <= j)
            {
                V[i][j] = max(V[i-1][j] , val[i-1] + V[i-1][j - wt[i-1]]);
            }else{
                V[i][j] = V[i-1][j];
            }
        }
    }


    cout << "The n cross W matrix is : \n";
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            cout << V[i][j] << "\t";
        }
        cout << endl;
    }

    // For Item Included
    int i = n , j = W;
    while(i>0 && j>0)
    {
        if(V[i-1][j] != V[i][j])
        {
            res[ct++] = i;
            j = j-wt[i-1];
        }
        i--;
    }
    return V[n][W];
}


int main()
{
    int n;
    cout << "Enter the Number of elements  : ";
    cin >> n;
    int wt[100];
    cout << "Enter the Weights : ";
    for(int i=0;i<n;i++)
    {
        cin >> wt[i];
    }

    int val[100];
    cout << "Enter the Corresponding values of weights : ";
    for(int i=0;i<n;i++)
    {
        cin >>val[i];
    }

    int W;
    cout << "Enter the Capacity of Knapsack : ";
    cin >> W;

    int Optimal = KnapSack(W , wt , val , n );
    cout << "The Optimal Profit is : " << Optimal << endl;

    cout << "Items Included are : ";
    for(int i=0;i<ct;i++)
    {
        cout << "Item " << res[i] << " of value " << val[res[i] - 1] << endl;
    }
}

// Enter the Number of elements  : 4
// Enter the Weights : 3 4 6 5
// Enter the Corresponding values of weights : 2 3 1 4
// Enter the Capacity of Knapsack : 8
// The n cross W matrix is : 
// 0       0       0       0       0       0       0       0       0
// 0       0       0       2       2       2       2       2       2
// 0       0       0       2       3       3       3       5       5
// 0       0       0       2       3       3       3       5       5
// 0       0       0       2       3       4       4       5       6
// The Optimal Profit is : 6
// Items Included are : Item 4 of value 4
// Item 1 of value 2