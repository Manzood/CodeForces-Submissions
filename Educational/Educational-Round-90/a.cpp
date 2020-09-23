#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int a,b,c;
		cin>>a>>b>>c;
		if (a>=c) cout<<-1;
		else cout<<1;
		cout<<" ";
		if ((long long)c < (long long)a*b) cout<<b;	
		else cout<<-1;
		cout<<'\n';
	}
}