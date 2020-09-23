#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define int long long

int32_t main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		scanf("%lld",&n);
		vector <int> a(n);
		for (int i=0;i<n;i++) {
			scanf("%lld",&a[i]);
		}
		// each time odd pref is greater than even pref, store it
		// each time even pref is greater, the previous subarray is already desirable for all future subarrrays
		// store the gain, add it to the final answer
		int m=0;
		int gain=0;
		int sum=0;
		for (int i=0;i<n;i++) {
			if (gain<0) gain=0;
			if (i%2==1) gain+=a[i]-a[i-1];
			if (i%2==0) {
				sum+=a[i];
			}
			m=max(gain,m);
		}
		gain=0;
		for (int i=n-1;i>=0;i--) {
			if (gain<0) gain=0;
			if (i%2==1 && i<n-1) gain+=a[i]-a[i+1];
			m=max(gain,m);
		}
		m+=sum;
		printf("%lld\n",m);
	}
}