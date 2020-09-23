#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int n,a,r,m;
	cin>>n>>a>>r>>m;
	vector <int> a(n);
	for (int i=0;i<n;i++) {
		scanf("%d",a[i]);
	}
	int cost=0;
	int costper=min(m,a+r);
	costper=min(min(m,a),min(m,r));
	