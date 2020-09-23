#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d",&n);
		bool printed = false;
		for (int i=2;(i*i)<=n && printed == false;i++) {
			if (n%i==0) {
				printf("%d %d\n",n/i, (n-n/i));
				printed = true;
			}
		}
		if (!printed) {
			printf("%d %d\n", 1, n-1);
		}
	}
}