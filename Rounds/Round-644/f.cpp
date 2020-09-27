#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n,m;
		scanf("%d%d",&n,&m);
		vector <string> a(n);
		for (int i=0;i<n;i++) {
			cin>>a[i];
		}
		bool found=false;
		string ans;
		for (int i=0;i<m && !found;i++) {
			int temp=a[0][i];
			for (char j='a';j<='z' && !found;j++) {
				a[0][i]=j;
				//debug(a[0]);
				bool possible=true;
				for (int x=1;x<n;x++) {
					int cnt=0;
					//debug(a[0]);
					//debug(a[x]);
					for (int y=0;y<m;y++) {
						if (a[0][y]!=a[x][y]) 
							cnt++;
						if (cnt>1)
							possible=false;
					}
				}
				//debug(possible);
				if (possible) {
					ans=a[0];
					found=true;
				}
			}
			a[0][i]=temp;
			//debug(a[0]);
		}
		if (found) 
			cout<<ans<<endl;
		else
			cout<<"-1"<<endl;
	}
}