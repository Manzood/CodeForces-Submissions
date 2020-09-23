//upsolving, didn't take part in this contest
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
#include<iostream>

using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		long long x,y;
		cin>>x>>y;
		long long a,b;
		cin>>a>>b;
		long long cost;
		if (b<2*a) {
			//b is good
			//to check if signs are different, we can check if abs(a)+abs(b)== abs(a+b)
			if ((abs(x)+abs(y))==abs(x+y)) {
				//same sign
				cost=(b*(min(x,y))+(max(x,y)-min(x,y))*a);
			}
			else {
				cost=a*(abs(x)+abs(y));
			}
		}
		else {
			//use only a
			cost=a*(abs(x)+abs(y));
		}
		cout<<cost<<endl;
	}
}