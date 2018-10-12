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
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    int arr[n];
	    for (int i = 0; i < n; ++i)
	    {
	    	cin>>arr[i];
	    	//todo shift everything over here
	    }

	    int count=0;
	    int c=0,p=0;
	    int sum=0;
	    bool flag=false;
	    
	    while(true) {
	        if(c<n) {
	        	for (int i = p; i <= c; ++i)
	        	{
	        		sum+=arr[i];
	        		if(sum>n){
	        		    flag=true;
	        		    break;
	        		}
	        	}
	        	cout<<"p:"<<p<<" c:"<<c<<" sum:"<<sum<<"\n"; //Debug
	        	p=c+1;
	        	c=sum;
	        	if(!flag)
	        	    count++;
	        }
	        else{
	            break;
	        }
	    }
	    cout<<count<<"\n";
	}
	return 0;
}
