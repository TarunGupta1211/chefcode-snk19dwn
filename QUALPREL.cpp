//
//Qualifying to Pre-elimination
//Problem Code: QUALPREL
//
//https://www.codechef.com/SNCKQL19/problems/QUALPREL
//

#include <iostream>
using namespace std;

//Quick Sort then Find

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 


int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] >= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  

void sort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        sort(arr, low, pi - 1); 
        sort(arr, pi + 1, high); 
    } 
}

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

	    sort(arr,0,n-1);
	    
        //for(int i=0;i<n;i++)    //check sorting
        	 //printf("%d",arr[i]);
    
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
/*void sort(int *arr,int n){
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
}*/
