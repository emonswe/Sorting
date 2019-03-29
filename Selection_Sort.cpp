#include<bits/stdc++.h>

using namespace std;
void selection_sort(int arr[],int n)
{
    int i,j,min_index,temp;

    for(i=0;i<n;i++){
        min_index=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_index])
                min_index=j;

        }
        if(min_index!=i)
        {
            temp=arr[i];
            arr[i]=arr[min_index];
            arr[min_index]=temp;
        }
        cout<<arr[i]<<" ";
    }




}
int main()
{
    int n,arr[20];
    int i;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>arr[i];
    for(i=0; i<n; i++)
        cout<<arr[i]<<" ";
        cout<<endl;
        selection_sort(arr,n);

    return 0;
}
