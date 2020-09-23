#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

//prime factorise it

int main() {
	long long k;
	cin>>k;
	string s="codeforces";
	vector <long long> count(10);
	for (int i=0;i<10;i++) {
		count[i]=1;
	}
	long long ans=1;
	int i=0;
	while (ans<k) {
		ans/=count[i];
		count[i]++;
		ans*=count[i];
		i++;
		if (i==10)
			i=0;
	}
	for (int i=0;i<10;i++) {
		for (int j=0;j<count[i];j++) {
			printf("%c",s[i]);
		}
	}
}