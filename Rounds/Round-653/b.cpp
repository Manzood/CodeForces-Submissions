#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t; cin>>t;
	while (t--) {
		int n;
		scanf("%d",&n);
		int ans=0;
		while (n>1 && (n%3 == 0)) {
			if (n%2==0) {
				n/=6;
			}
			else n*=2;
			ans++;
		}
		if (n>1) printf("-1\n");
		else printf("%d\n",ans);
	}
}