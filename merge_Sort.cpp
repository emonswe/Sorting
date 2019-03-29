#include<bits/stdc++.h>

using namespace std;


int _merge(int A[],int left,int mid,int right)
{
    int size_left,size_right;

    size_left = mid - left+1;
    size_right = right - mid;

    int L[size_left],R[size_right];


    for( int i=0; i<size_left; i++ )
        L[i] = A[left+i];

    for( int i=0; i<size_right; i++ )
        R[i] = A[mid+1+i];

    int i,j,k;
    i=0;
    j=0;
    k=left;

    while( i < size_left && j < size_right )
    {
        if( L[i] <= R[j] )
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < size_left)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    while( j < size_right )
    {
        A[k] = R[j];
        j++;
        k++;
    }
}


void merge_sort(int A[], int left, int right)
{
    if( left >= right )
        return;

    int mid = left + (right-left)/2;

    merge_sort(A,left,mid);
    merge_sort(A,mid+1,right);

    _merge(A,left,mid,right);
}

void printArray(int A[],int _size)
{
    for( int i=0; i<_size; i++ )
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}


int main()
{
    int A[] = {12,11,13,5,6,7};
    int _size = sizeof(A)/sizeof(A[0]);

    //for( int i=0; i<_size; i++ )
        //printArray(A,_size);

    merge_sort(A,0,_size-1);
    printArray(A,_size);

    return 0;
}
