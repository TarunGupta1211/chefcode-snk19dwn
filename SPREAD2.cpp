//
//Spread the Word 
//Problem Code: SPREAD2
//
//https://www.codechef.com/SNCKQL19/problems/SPREAD2
//

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    int arr[n];
	    for (int i = 0; i < n; ++i)
	    {
	    	cin>>arr[i];
	    }

	    int count=0;
	    int c=1,p=0;
	    int sum=0;
	    
	    while(true) {
	        if(c<n) {
	        	for (int i = p; i <= c; ++i)
	        	{
	        		sum+=arr[i];
	        		if(sum>n)
	        			break;
	        	}
	        	//cout<<"p:"<<p<<" c:"<<c<<" sum:"<<sum<<"\n"; //Debug
	        	p=c;
	        	c=sum;
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
