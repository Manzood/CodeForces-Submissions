#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		string s;
		cin>>s;
		long long res=0;
		long long curr=0;
		for (int i=0;i<s.size();i++) {
			char x=s[i];
			if (x=='-' && curr==0) {
				res++;
				res+=(i+1);
				curr=0;
			}
			else if (x=='-') {
				curr--;
				res++;
			}
			else {
				curr++;
				res++;
			}
			// debug(res);
			// debug(curr);
		}
		printf("%lld\n",res);
	}
}