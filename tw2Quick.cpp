#include<bits/stdc++.h>
using namespace std;
#define max 1000
int A[max] , B[max];



void Swap(int *a , int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition(int low , int high)
{
    int pivot = A[low];
    int i = low-1 , j = high+1;
    do{
        do{i++;}while(A[i] < pivot);
        do{j--;}while(A[j] > pivot);
        if(i<j)
            Swap(&A[i] , &A[j]);
    }while(i<j);
    Swap(&A[j] , &A[low]);
    return j;
}

void QuickSort(int low , int high)
{
    if(low < high)
    {
        int j = Partition(low , high);
        QuickSort(low , j-1);
        QuickSort(j+1 , high);
    }
}

int main()
{
    int n;
    time_t s , e;
    cout << "Enter the Number of Elements : ";
    cin >> n;
    cout << "The Elements are : ";
    for(int i=0;i<n;i++)
    {
        A[i] = rand()%100;
        cout << A[i] << "\t";
    }
    cout << endl;

    s = clock();
    for(int i=0;i<100000;i++)
        QuickSort(0 , n-1);
    e = clock();

    cout << "Elements after sorting : ";
    for(int i=0;i<n;i++)
    {
        cout << A[i] <<"\t";
    }
    cout << endl;

    double cpu_time = (double)(e-s)/CLK_TCK;
    cout << "Time : " << cpu_time << endl;
}