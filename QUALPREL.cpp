//
//Qualifying to Pre-elimination
//Problem Code: QUALPREL
//
//https://www.codechef.com/SNCKQL19/problems/QUALPREL
//

#include <bits/stdc++.h>
using namespace std;

//Quick Sort then Find

void swap(long *a, long *b)
{
    long t = *a;
    *a = *b;
    *b = t;
}


int partition (long *arr[], int low, int high)
{
    long pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] >= pivot) {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void sort(long *arr[], int low, int high)
{
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        sort(arr, low, pi - 1);
        sort(arr, pi + 1, high);
    }
}

void search(long *arr, int, int);

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d",&t);
    while(t--) {
        int n, k;
        scanf("%d",&n);
        scanf("%d",&k);
        long arr[n];
        for (int i = 0; i < n; ++i) {
            scanf("%ld", &arr[i]);
        }

        sort(arr, 0, n - 1);

        //Display Array
        /*
        cout<<"\n";
        for(int i = 0; i < n; i++)
            printf("%ld ", arr[i]);
        cout << "\n";
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

    /*if(h > l) {
        h = l;
        //l = h - l;
    }
    for (int i = h+1; i < n ; ++i) {
        cout << i;
        if(arr[i] < temp) {
            printf(" %d\n", i);
            break;
        }
    }*/

    printf("%d\n", l);
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
