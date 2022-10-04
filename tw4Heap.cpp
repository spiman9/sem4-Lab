#include<bits/stdc++.h>
using namespace std;

void Swap(int *a , int *b)
{
    int  t = *a ;
    *a = *b;
    *b = t;
}

void Heapify(int A[] , int n , int i)
{
    int largest = i;
    int l = 2*i;
    int r = 2*i+1;

    if(l<=n && A[largest] <= A[l])
    {
        largest = l;
    }

    if(r<=n && A[largest] <= A[r])
    {
        largest = r;
    }

    if(largest != i)
    {
        Swap(&A[largest] , &A[i]);
        Heapify(A , n , largest);
    }
}

void HeapSort(int A[] , int n )
{
    for(int i=n/2;i>=1;i--)
    {
        Heapify(A , n , i);
    }

    for(int i=n;i>=1;i--)
    {
        Swap(&A[1] , &A[i]);
        Heapify(A , i-1 , 1);
    }
}

int main()
{
    int n;
    cout << "Enter the Numebr of elements : ";
    cin >> n;
    cout << "Elements are : ";
    int A[n+1];
    for(int i=1;i<=n;i++)
    {
        A[i] = rand()%100;
        cout << A[i] << "\t";
    }
    time_t s , e;

    s=clock();
    for(int i=0;i<100000;i++)
    {
        HeapSort(A , n);
    }
    e = clock();


    cout << "\n\nSorted List : ";
    for(int i=1;i<=n;i++)
    {
        cout << A[i] << "\t";
    }

    double cputime = (double)(e-s)/CLK_TCK;
    cout << "\n\nTime : " << cputime << endl;
}