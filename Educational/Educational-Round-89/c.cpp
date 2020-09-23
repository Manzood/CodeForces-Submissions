#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n,m;
		scanf("%d%d",&n,&m);
		// for each distance, store their values. If there is a deviation, measure it
		vector <vector <int> > a(n);
		vector <vector <int> > dist(n+m-1);
		int temp;
		for (int i=0;i<n;i++) {
			for (int j=0;j<m;j++) {
				scanf("%d",&temp);
				a[i].push_back(temp);
				dist[i+j].push_back(temp);
			}
		}
		int ans=0;
		for (int i=0;i<dist.size()/2;i++) {
			int count=0;
			for (int j=0;j<dist[i].size();j++) {
				if (dist[i][j]==0) { 
					count++;
					// debug(i);
				}
			}
			// ans+=min(count,(int)dist[i].size()-count);
			for (int j=0;j<dist[m+n-i-2].size();j++) {
				if (dist[m+n-i-2][j]==0) {
					count++;
					// debug(i);
				}
			}
			ans+=min(count,(int)dist[m+n-i-2].size()+(int)dist[i].size()-count);
		}
		printf("%d\n",ans);
	}
}