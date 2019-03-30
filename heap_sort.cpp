#include<bits/stdc++.h>

using namespace std;
int left(int i)
{
    return 2*i;
}
int right(int i)
{
    return 2*i+1;
}
int parent(int i)
{
    return i/2;
}
void heapfy(int heap[],int heap_size, int i)
{
    int temp,l,r,largest;

    l=left(i);
    r=right(i);
    if(l<=heap_size && heap[l]>heap[i] )
    {
        largest=l;
    }
    else
        largest=i;

        if(r<=heap_size && heap[r]>heap[largest])
        {
            largest=r;
        }
        if(largest!=i)
        {
            temp=heap[i];
            heap[i]=heap[largest];
            heap[largest]=temp;

            heapfy(heap,heap_size,largest);
        }
    }
    void built_heap(int heap[],int heap_size)
    {
        int i;
        for(i=heap_size/2;i>=1;i--)
        {
            heapfy(heap,heap_size,i);
        }
    }
    void HeapSort(int heap[],int heap_size)
    {
        int i,temp;
        built_heap(heap,heap_size);
        for(i=heap_size;i>=1;i--)
        {
            temp=heap[1];
            heap[1]=heap[i];
            heap[i]=temp;

            heap_size-=1;
            heapfy(heap,heap_size,1);
        }
    }
int main()
{
    int heap_size,i;
    cin>>heap_size;
    int heap[heap_size];
    heap[0]=0;
    for(i=1; i<=heap_size; i++)
    {
        cin>>heap[i];
    }
    HeapSort(heap,heap_size);
    for(i=1;i<=heap_size;i++)
    {
        cout<<heap[i]<<" ";
    }

    return 0;
}
