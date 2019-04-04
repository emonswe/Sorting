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
void heapify(int heap[],int heap_size,int i)
{
    int l,r,temp,mini;
    l=left(i);
    r=right(i);
    if(l<=heap_size && heap[l]<heap[i])
    {
        mini=l;
    }
    else
        mini=i;
    if(l<=heap_size && heap[r]<heap[mini])
        mini=r;

    if(mini!=i)
    {
        temp=heap[i];
        heap[i]=heap[mini];
        heap[mini]=temp;
        heapify(heap,heap_size,mini);
    }
}
void heap_built(int heap[],int heap_size)
{
    int i;
    for(i=heap_size/2; i>=1; i--)
    {
        heapify(heap,heap_size,i);
    }

}


int main()
{
    int i,heap_size;
    cin>>heap_size;
    int heap[heap_size];
    for(i=1; i<=heap_size; i++)
        cin>>heap[i];

    heap_built(heap,heap_size);
    for(i=1;i<=heap_size;i++)
        cout<<heap[i]<<" ";
    return 0;
}
