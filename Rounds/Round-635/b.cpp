#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<iostream>

using namespace std;

#define debug(x) cout<<x<<endl;

int main () {
	int t;
	cin>>t;
	while (t--) {
		int x, n, m;
		scanf("%d %d %d",&x, &n, &m);
		while (n>0 && x>20) {
			x=x/2;
			x+=10;
			n--;
			//debug(x);
		}
		while (x>0 && m>0) {
			x-=10;
			m--;
			//debug(x);
		}

		if (x>0) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}
}