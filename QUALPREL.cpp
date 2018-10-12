//
//Qualifying to Pre-elimination
//Problem Code: QUALPREL
//
//https://www.codechef.com/SNCKQL19/problems/QUALPREL
//

#include <iostream>
using namespace std;

//Quick Sort then Find

void sort(int *,int n);

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
	    int n,k;
	    cin>>n>>k;
	    
	    int arr[n];
	    for (int i = 0; i < n; ++i)
	    {
	    	cin>>arr[i];
	    }

	    sort(arr,n);

	    //get the item;
	    int temp=arr[k-1];

	    //can be better
	    for (int i = k; i < n; ++i)
	    {
	    	if(arr[i]<temp) {
	    		cout<<i<<"\n";
	    		break;
	    	}
	    }
	}
	return 0;
}

//Do QuickSort Here
void sort(int *arr,int n){
    int x;
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = 0; j < n-i-1; ++j)
		{
			if(arr[j+1]>arr[j]) {
				x=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=x;
			}
		}
	}
}