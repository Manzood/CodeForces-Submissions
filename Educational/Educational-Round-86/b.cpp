#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<iostream>

using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		string s;
		cin>>s;
		string res;
		int next=s[0];
		int change=0;
		for (int i=0;i<s.size();i++) {
			if (s[i]!=next) {
				change=1;
			}
		}
		if (change==1) {
			for (int i=0;i<s.size();i++) {
				if (s[i]==next) {
					res+=s[i];
					if (next=='1') 
						next='0';
					else 
						next='1';
				}
				else {
					res+=next;
					res+=s[i];
				}
			}
			cout<<res<<endl;
		}
		else {
			cout<<s<<endl;
		}
	}
}