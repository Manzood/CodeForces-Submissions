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
		int n, x;
		scanf("%d %d",&n,&x);
		vector <int> a(n);
		int even=0,odd=0;
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			if (a[i]%2==0)
				even++;
			else
				odd++;
		}
		bool possible=true;
		if (odd) {
			x--;
			odd--;
			x-=even;
			if (x>0) {
				if (x%2!=0) {
					if (even>0) {
						if (odd<x+1)
							possible=false;
					}
					else 
						possible=false;
				}
				if (odd<x) {
					possible=false;
				}
			}
		}
		else
			possible=false;
		if (possible)
			printf("Yes\n");
		else
			printf("No\n");
	}
}