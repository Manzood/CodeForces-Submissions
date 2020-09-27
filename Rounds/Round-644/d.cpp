#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n,k;
		scanf("%d%d",&n,&k);
		int m=-1;
		for (int i=1;i<=k && i*i<=n;i++) {
			if (n%i==0) {
				//debug(m);
				if (m==-1)
					m=n/i;
				else
					m=min(n/i,m);
				if (n/i<=k)
					m=min(m,i);
			}
		}
		printf("%d\n",m);
	}
}