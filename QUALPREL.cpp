//
//Qualifying to Pre-elimination
//Problem Code: QUALPREL
//
//https://www.codechef.com/SNCKQL19/problems/QUALPREL
//

#include <bits/stdc++.h>
using namespace std;

//Quick Sort then Find

void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 

void search(long *arr, int, int);

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;

        long arr[n];
        for (int i = 0; i < n; ++i) {
            scanf("%ld", &arr[i]);
        }

        heapSort(arr, 0, n - 1);

        //Display Array
        
       // cout<<"\n";
        //for(int i = 0; i < n; i++)
         //   printf("%ld ", arr[i]);
        /*cout << "\n";
        for(int i = 0; i < k - 1; i++)
            printf("  ");
        cout << "^\n\n";
        */

        search(arr, n, k);
    }

    return 0;
}

void search(long *arr, int n, int k)
{
    //get the item;
    int temp = arr[k - 1];
    int blog = ceil(log2(n - k));

    int l = k, h = n - 1, pm, m = 0;
    while(blog--) {
        pm = m;
        m = (l + h) / 2;

        if(arr[m] >= temp)
            l = m + 1;

        else if(arr[m] < temp)
            h = m - 1;

        //cout << "l:" << l << " h:" << h << " m:" << m << " pm:" << pm << "\n"; //Debug

        if(m == pm)
            break;

    }

    if(h > l) {
        h = l;
        //l = h - l;
    }
    for (int i = h+1; i < n ; ++i) {
        cout << i;
        if(arr[i] < temp) {
            printf(" %d\n", i);
            break;
        }
    }

    //printf("%d\n", l);
}
/*for
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
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
}*/
© 2018 GitH
