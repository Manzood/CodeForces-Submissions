#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
	int t; cin>>t;
	while (t--) {
		long long n, k;
		scanf("%lld %lld",&n,&k);
		unordered_map<long long, int, custom_hash> a;
		long long x=0;
		for (int i=0;i<n;i++) {
			long long temp;
			scanf("%lld",&temp);
			if (temp%k>0) {
				temp=k-temp%k;
				a[temp]++;
				long long val=temp+((long long)k*(a[temp]-1));
				x=max(val+1,x);
			}
		}
		if (x>0)
			printf("%lld\n",x);
		else 
			printf("0\n");
	}	
}
