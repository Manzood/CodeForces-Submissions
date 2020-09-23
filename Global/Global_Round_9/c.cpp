#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		scanf("%d",&n);
		vector <int> a(n);
		int first=-1, last=-1;
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			if (i==0) 
				first=a[i];
			if (i==n-1) 
				last=a[i];
		}
		if (first>last) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}
}