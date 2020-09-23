#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<iostream>

using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		scanf("%d",&n);
		bool impossible=false;
		vector <int> ans(n);
		if ((n/2)%2==1) {
			impossible=true;
		}
		else {
			int pos=0;
			for (int i=1;i<=n;i++) {
				//debug(i);
				if (i%2==0) {
					ans[pos++]=i;
				}
				else {
					ans[pos+(n/2)]=i;
				}
			}
			ans[n-1]+=n/2;
		}
		if (impossible) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
			for (int i=0;i<n;i++) {
				printf("%d ",ans[i]);
			}
			printf("\n");
		}
	}	
}