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
		int n;
		scanf("%d",&n);
		vector <int> a(n);
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
		}
		int alice=0;
		int bob=0;
		int moves=0;
		int aptr=0;
		int bptr=a.size()-1;
		int previous=0;
		bool next=false;
		int current=0;
		bool moved=false;
		while (aptr<=bptr) {
			if (!next) {
				if (moved==false) {
					moves++;
					moved=true;
				}
				alice+=a[aptr];
				current+=a[aptr];
				aptr++;
				if (current>previous) {
					next=true;
					previous=current;
					current=0;
					moved=false;
				}
			}
			else {
				if (moved==false) {
					moves++;
					moved=true;
				}
				bob+=a[bptr];
				current+=a[bptr];
				bptr--;
				if (current>previous) {
					next=false;
					previous=current;
					current=0;
					moved=false;
				}
			}
		}
		printf("%d %d %d\n",moves,alice,bob);
	}
}
