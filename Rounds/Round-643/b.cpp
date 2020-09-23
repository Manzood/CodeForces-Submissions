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
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
		}
		sort(a.begin(),a.end());
		int ans=0;
		int group=1;
		for (int i=0;i<n;i++) {
			// debug(a[i]);
			// debug(group);
			if (a[i]<=group) {
				group=1;
				ans++;
			}
			else {
				group++;
			}
		}
		printf("%d\n",ans);
	}
}