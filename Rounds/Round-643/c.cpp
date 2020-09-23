#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int a,b,c,d;
	scanf("%d %d %d %d\n",&a,&b,&c,&d);
	long long ans=0;
	//prefix sums approach is BEAUTIFUL
	//solved after referring to a video by Aryan Mittal on youtube (I think that was his name)
	//Basically, the approach counts the number of possible sums of x and y and stores it in prefix sums.
	//Then it checks the number of values of z that are less than each sum and greater than c in O(n) time at the end, 
	//which is the answer!
	vector <int> bounds(c+b+2,0);
	for (int i=a;i<=b;i++) {
		bounds[i+b]+=1;
		bounds[i+c+1]-=1;
	}
	vector <int> prefix(b+c+2);
	for (int i=0;i<prefix.size();i++) {
		if (i==0)
			prefix[i]=bounds[i];
		else 
			prefix[i]=prefix[i-1]+bounds[i];
	}
	// for (int x: prefix)
		// debug(x);
	for (int i=0;i<prefix.size();i++) {
		if (prefix[i]>0) {
			if (i>c) {
				ans+=(long long)min(i-c,(d-c+1))*prefix[i];
			}
		}
	}
	printf("%lld\n",ans);
}
