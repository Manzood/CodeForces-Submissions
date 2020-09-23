#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n,k;
		scanf("%d %d",&n,&k);
		long long ans=0;
		if (k%(n-1)!=0) {
			ans+=(n*(k/(n-1)));
			k%=(n-1);
		}
		else {
			ans+=(n*(k/(n-1)-1));
			k=(k%(n-1))+(n-1);
		}
		ans+=k;
		printf("%lld\n",ans);
	}
}