#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n,x,m;
		scanf("%d%d%d",&n,&x,&m);
		int l,r;
		int lower=x,upper=x;
		for (int i=0;i<m;i++) {
			scanf("%d%d",&l,&r);
			if (l<=upper && r>=lower) {
				if (l < lower) 
					lower=l;
				if (r > upper)
					upper=r;
			}
		}
		printf("%d\n",upper-lower+1);
	}	
}