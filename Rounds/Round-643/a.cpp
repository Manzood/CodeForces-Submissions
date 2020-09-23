#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		long long a,k;
		scanf("%lld %lld",&a,&k);
		for (int i=1;i<k;i++) {
			long long temp=a;
			int mindigit=-1;
			int maxdigit=-1;
			while (temp) {
				int digit=temp%10;
				if (mindigit==-1) 
					mindigit=digit;
				else if (digit<mindigit)
					mindigit=digit;
				if (digit>maxdigit)
					maxdigit=digit;
				temp/=10;
			}
			a+=(mindigit*maxdigit);
			if (mindigit==0)
				break;
		}
		printf("%lld\n",a);
	}
}