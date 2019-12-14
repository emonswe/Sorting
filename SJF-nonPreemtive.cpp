#include <iostream>
#include <algorithm>

using namespace std;

int gVar;

typedef struct Process
{
	string process_ID;
	int at,bt,ct,ta,wt;

}Process;

bool compareArrivalTime(Process a,Process b)
{
	return a.at < b.at;
}

bool compareBurstTime(Process a,Process b)
{
	return a.bt < b.bt && a.at <= gVar;
}

int main()
{
	Process obj_Pro[10];
    int n,i,j,sum=0,sum1=0;

	cout<<"Enter the number of Process:";
	cin>>n;
	cout<<"Enter the Process id, arrival time and burst time :::";

	for(i=0;i<n;i++)
	{
		cin>>obj_Pro[i].process_ID;
		cin>>obj_Pro[i].at;
		cin>>obj_Pro[i].bt;
	}

	sort(obj_Pro,obj_Pro+n,compareArrivalTime);

	obj_Pro[0].ct=obj_Pro[0].bt+obj_Pro[0].at;


	obj_Pro[0].ta=obj_Pro[0].ct-obj_Pro[0].at;

	obj_Pro[0].wt=obj_Pro[0].ta-obj_Pro[0].bt;


	for(i=1;i<n;i++)
	{
		gVar=obj_Pro[i-1].ct;
		sort(obj_Pro+i,obj_Pro+n,compareBurstTime);
		if(obj_Pro[i-1].ct<obj_Pro[i].at)
		{
		   	obj_Pro[i].ct=obj_Pro[i-1].ct+obj_Pro[i].bt+(obj_Pro[i].at-obj_Pro[i-1].ct);
		}
		else
		{
		   	obj_Pro[i].ct=obj_Pro[i-1].ct+obj_Pro[i].bt;

		}
		obj_Pro[i].ta=obj_Pro[i].ct-obj_Pro[i].at;
		obj_Pro[i].wt=obj_Pro[i].ta-obj_Pro[i].bt;
        sum=sum+obj_Pro[i].wt;
        sum1=sum1+obj_Pro[i].ta;
	}
cout<<"ProID\tAtime\tBtime\tCtime\tTtime\tWtime\n";
	for(i=0;i<n;i++)
	{

		cout<<obj_Pro[i].process_ID<<"\t"<<obj_Pro[i].at<<"\t"<<obj_Pro[i].bt
		<<"\t"<<obj_Pro[i].ct<<"\t"<<obj_Pro[i].ta<<"\t"<<obj_Pro[i].wt;

		cout<<endl;
	}
	cout<<"Average Waiting Time: "<<(double)sum/n<<endl<<"Average Turnaround Time: "<<(double)sum1/n<<endl;

	return 0;
}
