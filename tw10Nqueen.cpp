#include<bits/stdc++.h>
using namespace std;
int ans = 0;
bool isSafe(int A[][40], int x , int y , int n)
{
    for(int row = 0 ; row<=x ;row++)
    {
        if(A[row][y] == 1)
        {
            return false;
        }
    }
    int row = x;
    int col = y;
    while(row>=0 && col>=0)
    {
        if(A[row][col] == 1)
            return false;
        row--;
        col--;
    }

    row = x;
    col = y;
    while(row>=0 && col<n)
    {
        if(A[row][col] == 1)
            return false;
        row--;
        col++;
    }
    return true;
}


bool nQueen(int A[][40] , int x , int n)
{
    if(x>=n)
    {
        return true;
    }

    for(int col = 0;col<n;col++)
    {
        if(isSafe(A , x  , col , n))
        {
            A[x][col] = 1;
            if(nQueen(A , x+1 , n))
            {
                cout << "\n\nSolution  " << (++ans) << endl;
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        if(A[i][j] == 1)
                        {
                            cout << "Q\t";
                        }else{
                            cout << "*\t";
                        }
                    }
                    cout << endl;
                }
            }
            A[x][col] = 0;
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter the Number of Queens : ";
    cin >> n;
    int A[40][40];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            A[i][j] = 0 ;
        }
    }
    if(n == 2 || n==3)
    {
        cout << "No Solutions";
        return 0;
    }
    nQueen(A , 0 , n);

    cout << "\n\n\nNumber of Solutions are : " << ans << endl;
}