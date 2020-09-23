#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

set <char> visited;
bool dfs (vector <vector <char>> adj, char a, char b) {
	if (visited.count(a))
		return false;
	int curr = a - 'a';
	visited.insert(a);
	bool retval = false;
	for (char x: adj[curr]) {
		if (x == b) return true;
		if (dfs(adj, x, b) == true) 
			return true;
	}
	return retval;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		string a, b;
		cin >> a >> b;
		bool possible = true;
		vector <vector <char>> adj(20);
		map <pair <char, char>, bool> mp;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (b[i] < a[i]) {
				possible = false;
				break;
			}
			else if (b[i] > a[i]) {
				if (mp[make_pair(a[i], b[i])] == true) continue;
				visited.clear();
				if (!dfs(adj, a[i], b[i])) {
					adj[a[i]-'a'].push_back(b[i]);
					adj[b[i]-'a'].push_back(a[i]);
					mp[make_pair(a[i], b[i])] = true;
					if (adj[a[i]-'a'].size() == 19 || adj[b[i]-'a'].size() == 19) break;
					ans++;
				}
                if (visited.size() == 20) break;
			}
		}
		if (possible == false) printf("-1\n");
		else printf("%d\n", ans);
	}
}