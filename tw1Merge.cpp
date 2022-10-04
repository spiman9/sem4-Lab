#include<bits/stdc++.h>
using namespace std;
#include<time.h>
#define max 1000
int A[max] , B[max];

void Merge(int low , int mid , int high)
{
    int i = low , j = mid + 1 , k = low;
    while(i<=mid && j<=high)
    {
        if(A[i] <= A[j])
        {
            B[k++] = A[i++];
        }
        else{
            B[k++] = A[j++];
        }
    }
    while(i<=mid){
        B[k++] = A[i++];
    }

    while(j<=high)
    {
        B[k++] = A[j++];
    }

    for(int i=0;i<=high ;i++)
        A[i] = B[i];
}

void mergeSort(int low , int high)
{
    if(low < high)
    {
        int mid = (low + high)/2;
        mergeSort(low , mid);
        mergeSort(mid+1 , high);
        Merge(low , mid , high);
    }
}


int main()
{
    int n;
    time_t s , e;
    cout << "Enter the Number of Elements : ";
    cin >> n;
    cout << "Elements are : ";
    for(int i=0;i<n;i++)
    {
        A[i] = rand()%200;
        cout << A[i] << "\t";
    }

    cout << endl << endl;

    s= clock();
    for(int i=0;i<=100000;i++)
        mergeSort( 0 , n-1);
    e = clock();

    cout << "Elements after sorting are : ";
    for(int i=0;i<n;i++)
    {
        cout << A[i] << "\t";
    }

    double cpu_time = (double)(e-s)/CLK_TCK;
    cout << endl << "Time : " << cpu_time;
}