#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
 
int main() {
	int n;
	cin>>n;
	vector <int> a(n);
	vector <int> bits(20);
	vector <long long> ans(n);
	for (int i=0;i<20;i++) 
		bits[i]=0;
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
		int current=1;
		int pos=0;
		while (current<=a[i]) {
			if (current & a[i])
				bits[pos]++;
			current=current<<1;
			pos++;
		}
		ans[i]=0;
	}
	for (int i=0;i<a.size();i++) {
		int current=1;
		for (int j=0;j<20;j++) {
			if (bits[j]) {
				ans[i]+=current;
				bits[j]--;
			}
			current=current<<1;
		}
	}
	long long sq=0;
	for (int i=0;i<n;i++) {
		sq+=ans[i]*ans[i];
	}
	cout<<sq;
}	