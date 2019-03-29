#include<bits/stdc++.h>

using namespace std;

void insertion_sort(int arr[],int n)
{
    int i,temp,lift=1,val=0,k;
    while(lift!=n)
    {
        val=lift-1;
        k=lift;
        for(i=0; i<lift; i++)
        {

            if(arr[val]>arr[k])
            {
                temp=arr[val];
                arr[val]=arr[k];
                arr[k--]=temp;
                val--;

            }
            else
                break;
        }
        lift++;
    }
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

}

int main()
{
    int arr[20],i,n;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>arr[i];
    //for(i=0;i<n;i++)
    //cout<<arr[i]<<" ";
    cout<<endl;

    insertion_sort(arr,n);

    return 0;
}
