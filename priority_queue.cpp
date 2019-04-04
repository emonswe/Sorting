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
void heapify(int heap[],int heap_size,int i)
{
    int temp,l,r,largest;

    l=left(i);
    r=right(i);
    if(l<=heap_size && heap[l]>heap[i])
        largest=l;
    else
        largest=i;

    if(r<=heap_size && heap[r]>heap[largest])
        largest=r;
    if(largest!=i)
    {
        temp=heap[i];
        heap[i]=heap[largest];
        heap[largest]=temp;

        heapify(heap,heap_size,largest);
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
int extract_node(int heap[],int heap_size)
{
    int max_heap;
    max_heap=heap[1];
    heap[1]=heap[heap_size];

    heap_size-=1;
    heapify(heap,heap_size,1);


    return max_heap;
}
int insert_heap(int heap[],int heap_size)
{
    cout<<"Enter Value to Insert: "<<endl;
    int node,i;
    cin>>node;
    int p,temp;
    heap_size+=1;
    heap[heap_size]=node;
    i=heap_size;
    while(i>1 && heap[i]>heap[parent(i)] )
    {
        p=parent(i);
        temp=heap[i];
        heap[i]=heap[p];
        heap[p]=temp;
        i=p;
    }
    return heap_size;
}




int main()
{
    int heap_size,i,n,show;
    cout<<"Enter Heap_size: "<<endl;
    cin>>heap_size;
    int heap[heap_size];
    cout<<"Enter values: "<<endl;
    for(i=1; i<=heap_size; i++)
        cin>>heap[i];

    heap_built(heap,heap_size);
    for(i=1; i<=heap_size; i++)
    {
        cout<<heap[i]<<" ";
    }
    cout<<endl;


    while(n!=5)
    {
        cout<<endl<<"Press 1 to Extract: "<<endl;
        cout<<"Press 2 to Insert: "<<endl;
        cout<<"Press 3 to display: "<<endl;
        cout<<"press 4 to exit:"<<endl;
        cin>>n;
        switch(n)
        {
        case 1:
            show=extract_node(heap,heap_size);
            cout<<show<<endl;
            heap_size-=1;
            if(heap_size==1)
            {
                cout<<"Empty"<<endl;
            }
            break;
        case 2:
            heap_size=insert_heap(heap,heap_size);
            break;
        case 3:
            for(i=1; i<=heap_size; i++)
            {
                cout<<heap[i]<<" ";
            }
            break;
        case 4:
            n=5;
            break;
        default:
            cout<<"Wrong input!"<<endl<<"Try again"<<endl<<"Wanna Exit press 4"<<endl;
        }
    }
    return 0;
}
