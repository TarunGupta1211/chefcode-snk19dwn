//
//Qualifying to Pre-elimination
//Problem Code: QUALPREL
//
//https://www.codechef.com/SNCKQL19/problems/QUALPREL
//

#include <bits/stdc++.h>
using namespace std;

void merge(long int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(long int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
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

        mergeSort(arr, 0, n - 1);

        //Display Array
        /*
        cout << "\n";
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
    //cout<<"\nblog:"<<blog<<"\n";
    int l = k, h = n - 1, pm, m = 0;
    while(blog--) {
        //pm = m;
        m = (l + h) / 2;

        if(arr[m] >= temp)
            l = m + 1;

        else if(arr[m] < temp)
            h = m - 1;

        //cout << "l:" << l << " h:" << h << " m:" << m << " blog:" << blog << "\n"; //Debug

        //if(m == pm)
        //    break;

    }

    if(h < l) {
        for (int i = h; i < n ; ++i) {
            //cout << i;
            if(arr[i] < temp) {
                printf(" %d\n", i);
                break;
            }
        }
    } else {
        for (int i = l; i < n ; ++i) {
            //cout << i;
            if(arr[i] < temp) {
                printf(" %d\n", i);
                break;
            }
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
