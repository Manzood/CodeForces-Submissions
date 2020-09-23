#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<iostream>
#include<queue>

using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

//works
void dfs(vector <int>* tree, int node, bool visited[]) {
	if (visited[node]) return;
	visited[node]=true;
	for (auto current: tree[node]) {
		dfs(tree, current, visited);
	}
}

//works
int bfs (vector <int>* tree, int node, queue<int> q, bool visited[], int distance[]) {
	visited[node]=true;
	distance[node]=0;
	q.push(node);
	debug(node);
	while (!q.empty()) {
		int curr= q.front();
		q.pop();
		for (auto u: tree[curr]) {
			//debug(visited[u]);
			if (visited[u]) continue;
			visited[u]=true;
			distance[u]=distance[curr]+1;
			q.push(u);
			//debug(q.size());
			debug(u);
		}
	}
}

vector <pair<int,int>> cnt;
int getans(vector<int>*tree, int node, bool visited[]) {
	if (visited[node]) {
		return 1;
	}
	visited[node]=true;
	int returnval=0;
	for (auto u: tree[node]) {
		if (tree[node].size()==1) {
			cnt.emplace_back(u,1);
			return 1;
		}
		else {
			returnval+=getans(tree,u,visited);
		}
	}
	cnt.emplace_back(node,returnval);
	return returnval;
}

vector <int> visited;
vector <int> init(int n) {
	for (int i=0;i<n;i++) {
		visited.push_back(false);
	}
}

vector<pair<int,int>> getdepth(vector <int> *tree, int node, vector <pair<int,int>> depth, int d) {
	//debug(node);
	//debug(visited[node]);
	if (visited[node])
		return depth;
	if (tree[node].size()==1) {
		depth.emplace_back(node,d);
		return depth;
	}
	visited[node]=true;
	//debug("Made it here");
	for (auto u: tree[node]) {
		//debug(u);
		depth=getdepth (tree, u, depth, d+1);
	}
	depth.emplace_back(node,d);
	//debug(depth.size());
	return depth;
}

int main() {
	int n, k;
	cin>>n>>k;
	vector <int> tree[n];
	int u,v;
	for (int i=0;i<n-1;i++) {
		scanf("%d %d",&u,&v);
		tree[u-1].push_back(v-1);
		tree[v-1].push_back(u-1);
		//debug(u);
		//debug(v);
	}
	//debug("made it here");
	bool visited[n];
	for (int i=0;i<n;i++) {
		visited[i]=false;
	}
	queue<int>q;
	int dist[n];
	//dfs(tree,0,visited);
	int ans=getans(tree,0,visited);
	//debug(ans);
	vector <pair<int,int>> depth;
	init(n);
	depth=getdepth(tree,0,depth,0);
	debug(depth.size());
	for (int i=0;i<cnt.size();i++) {
		printf("%d %d\n",cnt[i].first,cnt[i].second);
	}
	debug(ans);
}
