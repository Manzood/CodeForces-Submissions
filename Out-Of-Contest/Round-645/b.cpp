#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
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
		int ans=1;
		sort(a.begin(),a.end());
		int last=0;
		for (int i=0;i<n;i++) {
			if (a[i]<=ans+(i-last)) {
				ans+=(i-last)+1;
				last=i+1;
			}
			//debug(ans);
		}	
		printf("%d\n",ans);
	}
}