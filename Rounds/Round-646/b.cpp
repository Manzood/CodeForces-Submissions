#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		string s;
		cin>>s;
		//prefix sum approach
		vector <int> a(s.size());
		for (int i=0;i<s.size();i++) {
			if (i==0) {
				a[i]=s[i]-'0';
			}
			else {
				a[i]=s[i]-'0'+a[i-1];
			}
		}
		int n=s.size();
		int m=min(a[n-1],n-a[n-1]);
		//debug(m);
		for (int i=0;i<n;i++) {
			m=min(min(i+1-a[i]+a[n-1]-a[i],a[i]+n-i-1-(a[n-1]-a[i])),m);
			//debug(m);
		}
		printf("%d\n",m);
	}
}