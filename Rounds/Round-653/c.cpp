#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		string s;
		cin>>s;
		int lcount=0;
		int rcount=0;
		int ans=0; 
		for (char x: s) {
			if (x=='(')
				lcount++;
			else 
				rcount++;
			if (rcount>lcount) {
				ans++;
				rcount--;
			}
		}
		printf("%d\n",ans);
	}
}