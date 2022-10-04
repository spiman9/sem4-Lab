#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, end) for (int i = start; i <= end; i++)
int ct = 0;
int min(int a, int b)
{
    return a > b ? b : a;
}
void printMatrix(int D[][40], int n)
{
    int i, j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(D[i][j] == 99)
            {
                cout << "inf" << "\t";
                continue;
            }
            cout << D[i][j] << "\t";
        }
        cout << endl;
    }
}

void Floyds(int D[][40], int n)
{
    
    for(int k=1;k<=n;k++)
    {
        printf("\n\nIntermediate as %d \n", ++ct);
        printMatrix(D , n);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                D[i][j] = min(D[i][j] , D[i][k] + D[k][j]);
            }
        }
    }
}


int main()
{
    int n;
    cout << "Enter the Number of Nodes : ";
    cin >> n;
    cout << "Enter into Adjancy Matrix : \n";
    int D[40][40];
    int i,j;
    for(i=1 ; i<=n ; i++)
    {
        for(j=1;j<=n;j++)
        {
            cin >> D[i][j];
        }
    }
    Floyds(D , n);
    cout << "\n\nFinal Cost Matrix is : \n";
    printMatrix(D , n);
}

// 0 5 99 10
// 99 0 3 99
// 99 99 0 1
// 99 99 99 0

//        10
//  (0)------->(3)
//   |         /|\
// 5 |          |
//   |          | 1
//  \|/         |
//  (1)------->(2)
//       3