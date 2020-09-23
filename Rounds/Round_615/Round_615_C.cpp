#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		scanf("%d",&n);
		int a=2;
		while (a*a<=n) {
			if (n%a==0) {
				n/=a;
				break;
			}
			a++;
		}
		int b=-1,c;
		for (int i=2;i*i<=n;i++) {
			if (n%i==0) {
				if (i!=a && i!=n/i && a!=n/i) {
					b=i;
					c=n/i;
					break;
				}
			}
		}
		if (b==-1) 
			printf("NO\n");
		else {
			printf("YES\n%d %d %d\n",a,b,c);
		}
	}
}