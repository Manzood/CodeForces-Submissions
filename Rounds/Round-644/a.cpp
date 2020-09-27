#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int a,b;
		scanf("%d%d",&a,&b);
		int side=max(max(a,b),min(a,b)*2);
		printf("%d\n",side*side);
	}
}