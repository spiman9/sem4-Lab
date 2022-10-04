#include<bits/stdc++.h>
using namespace std;
#define max 1000
#define rep(i , start , end ) for(int i=start;i<=end;i++)
int A[max];
void Insertion(int n)
{
    for(int i=1;i<n;i++)
    {
        int j = i-1;
        int temp = A[i];
        while(j>=0 && A[j] > temp)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;
    }
}

int main()
{
    int n;
    time_t s , e;
    cout << "Enter the Number of Elements : ";
    cin >> n;
    int i;
    cout << "Elements are : ";
    rep(i , 0 , n-1){
        A[i] = rand()%100;
        cout << A[i] << "\t";
    }


    s = clock();
    for(int i=0;i<100000;i++)
    {
        Insertion(n);
    }
    e=clock();

    
    cout << "\nElements in sorted order is :   ";
    rep(i , 0 , n-1)
    {
        cout << A[i] << "\t";
    }
    double cpu_time = (double)(e-s)/CLK_TCK;

    cout << endl << "Time : " << cpu_time << endl;

}