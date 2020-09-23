#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		string res;
		int n0,n1,n2;
		scanf("%d %d %d",&n0,&n1,&n2);
		if (n1==0) {
			if (n2) {
				for (int i=0;i<n2+1;i++) {
					res+='1';
				}
			}
			else if (n0) {
				for (int i=0;i<n0+1;i++) {
					res+='0';
				}
			}
		}
		else {
			for (int i=0;i<n2;i++) {
				res+='1';
			}
			bool one=true;
			bool first=true;
			for (int i=0;i<n1+1;i++) {
				if (one) {
					res+='1';
					one=false;
				}
				else {
					if (first==true) {
						for (int i=0;i<n0;i++) {
							res+='0';
						}
						first=false;
					}
					res+='0';
					one=true;
				}
			}
		}
		cout<<res<<endl;	
	}
}
