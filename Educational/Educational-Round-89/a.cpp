#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int a,b;
		scanf("%d%d",&a,&b);
		int ans=0;
		ans+=min(abs(a-b),min(a,b));
		if (a<b) {
			a-=ans;
			b=a;
		}
		else {
			b-=ans;
			a=b;
		}		
		ans+=(a/3)*2;
		if (a%3==2)
			ans++;
		printf("%d\n",ans);
	}	
}