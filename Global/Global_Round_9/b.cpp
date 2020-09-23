#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n, m;
		scanf("%d%d",&n,&m);
		bool possible=true;
		for (int i=0;i<n;i++) {
			for (int j=0;j<m;j++) {
				int temp; scanf("%d",&temp);
				if ((i==0 || i==n-1) && (j==0 || j==m-1)) {
					if (temp>2) possible=false;
				}
				else if (i==0 || i==n-1 || j==0 || j==m-1) {
					if (temp>3) possible=false;
				}
				else {
					if (temp>4) possible=false;
				}
			}
		}
		if (possible) {
			printf("YES\n");
			for (int i=0;i<n;i++) {
				for (int j=0;j<m;j++) {
					if ((i==0 || i==n-1) && (j==0 || j==m-1)) {
						printf("2 ");
					}
					else if (i==0 || i==n-1 || j==0 || j==m-1) {
						printf("3 ");
					}
					else printf("4 ");
				}
				if (i<n-1)
				printf("\n");
			}
			printf("\n");
		}
		else {
			printf("NO\n");
		}
	}
}