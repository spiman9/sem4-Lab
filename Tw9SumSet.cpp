#include<bits/stdc++.h>
using namespace std;
#define max 100
int inc[100] , w[100] , sum , n;

int prom(int i , int wt , int t)
{
    return (((wt+t) >= sum) && ((wt == sum) || (wt + w[i+1]<=sum)));
}

void sumset(int i , int wt , int t)
{
    if(prom(i , wt , t))
    {
        if(wt == sum)
        {
            cout << "{ ";
            for(int j = 0 ; j<=i ; j++)
            {
                if(inc[j] == 1)
                {
                    cout << w[j] << " ";
                }
            }
            cout << " }\n" ;
        }else{
            inc[i+1] = true;
            sumset(i+1 , wt + w[i+1] , t-w[i+1]);
            inc[i+1] = false;
            sumset(i+1 , wt , t - w[i+1]);
        }
    }
}

int main()
{
    cout << "Enter the Number of Elements : ";
    cin >> n;
    cout << "Enter the Elements : ";
    for(int i=0;i<n;i++)
    {
        cin >> w[i];
    }
    cout << "Enter the Sum : ";
    cin >> sum;
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i ;j++)
        {
            if(w[j+1] < w[j])
            {
                int t = w[j+1];
                w[j+1] = w[j];
                w[j] = t;
            }
        }
    }

    int t = 0;
    for(int i=0;i<n;i++)
    {
        t+=w[i];
        inc[i] = false;
    }
    if(t < sum )
    {
        cout << "No Solution";
        return 0;
    }
    cout << "Solution[s]\n";
    sumset(-1 , 0 , t);
}