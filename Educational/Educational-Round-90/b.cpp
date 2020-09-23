#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		string s;
		cin>>s;
		int zero=0;
		int one=0;
		for (int i=0;i<s.size();i++) {
			if (s[i]=='0') zero++;
			else one++;
		}
		if (min(zero,one)%2==1) printf("DA\n");
		else printf("NET\n");
	}
}