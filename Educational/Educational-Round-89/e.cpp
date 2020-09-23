#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main () {
	int n,m;
	cin>>n>>m;
	long long ans=1;
	vector <int> a(n);
	vector <int> b(m);
	vector <int> rightmost(m);
	for (int i=0;i<n;i++) 
		scanf("%d",&a[i]);
	for (int i=0;i<m;i++)  
		scanf("%d",&b[i]);
	int index=b.size()-1;
	for (int i=a.size()-1;i>=0 && index>=0;i--) {
		if (a[i]==b[index]) 
			rightmost[index--]=i;
	}
	for (int i=0;i<rightmost.size()-1;i++) {
		debug(ans);
		ans*=rightmost[i+1]-rightmost[i];
		ans%=998244353;
	}
	debug(ans);
	ans*=max(n-1-rightmost[m-1],1);
	ans%=998244353;
	printf("%lld\n",ans);	
}