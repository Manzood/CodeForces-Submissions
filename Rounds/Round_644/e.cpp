#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		scanf("%d",&n);
		char temp;
		getchar();
		vector <vector <int>> grid(n);
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				scanf("%c",&temp);
				if (temp=='1')
					grid[i].push_back(1);
				else
					grid[i].push_back(0);
			}
			scanf("\n");
		}
		bool possible=true;
		//debug(n);
		for (int i=0;i<n && possible==true;i++) {
			for (int j=0;j<n && possible==true;j++) {
				// debug(i);
				// debug(j);
				//printf("%d",grid[i][j]);
				if (grid[i][j]==1) {
					if (i==n-1 || j==n-1 || grid[i+1][j]==1 || grid[i][j+1]==1) {
						;
					}
					else 
						possible=false;
				}
			}
			// printf("\n");
		}
		if (possible)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
