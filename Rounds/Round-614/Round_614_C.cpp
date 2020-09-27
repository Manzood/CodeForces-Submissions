#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	vector <vector<int>> grid (n);
	for (int i=0; i<n; i++) {
		grid[i].push_back(0);
		grid[i].push_back(0);
	}
	for (int i=0; i<q; i++) {
		int r, c;
		scanf("%d %d", &c, &r);
		grid[r-1][c-1] = !grid[r-1][c-1];
		if (c == 2) {
			if (grid[r-1][c-1])
				//complete it eventually, if you know what's good for you
}