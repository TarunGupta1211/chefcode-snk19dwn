//
//Spread the Word
//Problem Code: SPREAD2
//
//https://www.codechef.com/SNCKQL19/problems/SPREAD2
//
//https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
//

//#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    //Site says makes the input faster
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n], pplLeft = n - 1;
        int count = 0, temp = 0;
        int c = 0, p = 0;
        int sum = 0, day = 0;
        bool flag = false;

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];

            if(pplLeft > 0) {

                sum += arr[i];
                if(temp == 0) {
                    temp = sum;
                    count++;
                    pplLeft -= sum;
                }

                temp--;

                //cout<<"pplLeft:"<<pplLeft<<" sum:"<<sum<<" temp:"<<temp<<" count:"<<count<<"\n";
            }
        }

        /*if(sum < n) {
            sum = sum + arr[i];
            day++;
        } else {
            if(flag = false) {
                flag = true;
            }
        }
        printf("%d ", sum);
        }
        /*/
        printf("%d\n", count);
    }
    return 0;
}