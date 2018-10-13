//
//Qualifying to Pre-elimination
//Problem Code: QUALPREL
//
//https://www.codechef.com/SNCKQL19/problems/QUALPREL
//

#include <iostream>
using namespace std;

//Quick Sort then Find

void swap(long* a, long* b) 
{ 
    long t = *a; 
    *a = *b; 
    *b = t; 
} 


int partition (long arr[], int low, int high) 
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
  

void sort(long arr[], int low, int high) 
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

void search(long *arr,int,int);

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
	    int n,k;
	    cin>>n>>k;
	    
	    long arr[n];
	    for (int i = 0; i < n; ++i)
	    {
	    	scanf("%ld",&arr[i]);
	    }

	    sort(arr,0,n-1);
	    
        //for(int i=0;i<n;i++)    //check sorting
        	 //printf("%d",arr[i]);
    
	    

	    //can be better
	    search(arr,n,k);
	}
	return 0;
}

void search(long *arr,int n,int k){
    //get the item;
	    int temp=arr[k-1];
	for (int i = k; i < n; ++i)
	    {
	    	if(arr[i]<temp) {
	    		printf("%d\n",i);
	    		break;
	    	}
	    }
}

int binarySearch(int arr[], int l, int r, int x) 
{ 
    while (l <= r) 
    { 
        int m = l + (r-l)/2; 
  
        // Check if x is present at mid 
        if (arr[m] == x) 
            return m; 
  
        // If x greater, ignore left half 
        if (arr[m] < x) 
            l = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            r = m - 1; 
    } 
  
    // if we reach here, then element was 
    // not present 
    return -1; 
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
