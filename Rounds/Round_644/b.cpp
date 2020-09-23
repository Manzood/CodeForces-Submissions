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
		int m=-1;
		for (int i=1;i<n;i++) {
			if(i==1) {
				m=a[i]-a[0];
			}
			else {
				m=min(a[i]-a[i-1],m);
			}
		}
		printf("%d\n",m);
	}
}
