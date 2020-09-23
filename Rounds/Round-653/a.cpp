#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t=1; 
	cin>>t;
	while (t--) {
		int x,y,n;
		scanf("%d%d%d",&x,&y,&n);
		int rem=n%x;
		int ans=n-rem+y;
		if (ans>n) ans-=x;
		printf("%d\n",ans);
	}
}