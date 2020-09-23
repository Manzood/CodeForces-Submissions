#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

pair<long long,long long> getans (long long n) {
	pair <long long,long long> ret;
	long long x=1;
	long long prev=1;
	long long ans=0;
	// debug(n);
	// debug(x);
	while (x<=n) {
		ans+=(ans+prev);
		x*=2;
	}
	x/=2;
	ret=make_pair(x,ans);
	return ret;
}

int main() {
	int t;
	cin>>t;
	while (t--) {
		//for each power of two, the new difference would be the previous power of two + 1
		long long n;
		scanf("%lld",&n);
		long long ans=0;
		long long x=1;
		int prev=1;
		pair<long long, long long> ret;
		while (n>0) {
			ret=getans(n);
			// debug(n);
			n-=ret.first;
			ans+=ret.second;
		}
		printf("%lld\n",ans);
	}
}