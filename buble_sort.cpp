#include<bits/stdc++.h>

using namespace std;

void buble_sort(int arr[],int n)
{
    int i,j,temp,lift,m;
    for(i=0;i<n;i++)
    {
        m=n;
       lift=0;
        for(j=lift+1;j<m;j++)
        {
            if(arr[lift]>arr[j])
            {
                temp=arr[lift];
                arr[lift]=arr[j];
                arr[j]=temp;
                lift++;
            }
            else
                lift++;
        }

        m--;
    }

    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
int main()
{
    int arr[20],i,n;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    /*
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    */
    buble_sort(arr,n);

    return 0;
}
