#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		long long a,b;
		scanf("%lld %lld",&a,&b);
		long long temp=a;
		int start=0;
		while (!(a & 1)) {
			a=a>>1;
			start++;
		} 
		 // debug(start);
		// debug(a);
		//find leftmost
		int leftmost;
		for (int i=0;i<64;i++) {
			if (a&(1LL<<i))
				leftmost=i;
		}
		int ops=-1;
		//debug(leftmost);
		for (int i=0;i<(64-leftmost+1);i++) {
			// debug(a);
			// debug(b);
			if (a<0)
				break;
			if (a==b) {
				//debug(temp);
				if (a<=temp) {
					ops=start-i;
				}
				else {
					ops=i-start;
				}
				break;
			}
			// debug(ops);
			a=a<<1;
		}
		if (ops!=-1) {
			temp=ops%3;
			ops=(ops/3);
			if (temp>0)
				ops++;
		}
		printf("%d\n",ops);
	}
}