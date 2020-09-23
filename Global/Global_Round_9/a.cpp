#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		vector <int> a(n);
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			if (i%2==0) {
				if (a[i]<0) {
					a[i]=-a[i];
				}
			}
			else {
				if (a[i]>0) {
					a[i]=-a[i];
				}
			}
		}
		for (int i=0;i<n;i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
}
