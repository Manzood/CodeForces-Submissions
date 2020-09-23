#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		scanf("%d",&n);
		vector <int> a(n);
		int m=0;
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			m=max(m,a[i]);
		}
		int ans;
		bool found=false;
		for (int x=1;x<(2*m);x++) {
			bool possible=true;
			set <int> used;
			for (int i=0;i<n;i++) {
				int temp=x^a[i];
				used.insert(temp);
			}
			for (int i=0;i<n;i++) {
				if (used.count(a[i])==0) {
					possible=false;
					break;
				}
			}
			if (possible) {
				found=true;
				ans=x;
				break;
			}
		}
		if (found)
			printf("%d\n",ans);
		else 
			printf("-1\n");
	}
}