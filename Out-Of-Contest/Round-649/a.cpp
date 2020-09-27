#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n,x;
		scanf("%d%d",&n,&x);
		vector <int> a(n);
		int firstdiv=-1,lastdiv=-1;
		int sum=0;
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			if (a[i]%x!=0 && firstdiv==-1)
				firstdiv=i;
			else if (a[i]%x!=0)
				lastdiv=i;
			sum+=a[i];
		}
		if (firstdiv==-1 && lastdiv==-1) {
			printf("-1\n");
		}
		else {
			if (sum%x!=0) {
				printf("%d\n",n);
			}
			else {
				printf("%d\n",max(n-firstdiv-1,lastdiv));
			}
		}
	}
}