#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		long long a,b,n;
		scanf("%lld%lld%lld",&a,&b,&n);
		int ans=0;
		while (max(a,b)<=n) {
			if (a<b) {
				a+=b;
			}
			else {
				b+=a;
			}
			ans++;
		}
		printf("%d\n",ans);
	}
}