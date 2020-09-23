#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

//recursive search
set <int> visited;
vector <int> ans;
bool search (int node, vector <int> *adj, vector <int> topics, bool ret) {
	if (visited.count(node))
		return ret;
	visited.insert(node);
	set <int> found;
	//for all nodes in the graph, find a node whose topic that doesn't belong to the neighbours 
	bool searched=false;
	for (auto u: adj[node]) {
		if (topics[node]==topics[u])
			ret=false;
		if (search(u,adj,topics,ret)==false)
			ret=false;
		searched=true;
	}
	if (searched==false) {
		for (int i=0;i<topics.size();i++) {
			if (visited.count(i)==0) {
				if (search(i,adj,topics,ret)==false)
					ret=false;
			}
		}
	}
	else {
		ans.push_back(node);
	} 
	return ret;
}

	// int selected=-1;
	/*set <int> neighbours;
	for (auto u: adj[node]) {
		neighbours.insert(topics[u]);
		if (selected!=-1)
			break;
	}
	for (int i=0;i<topics.size();i++) {
		if (neighbours.count(i+1)==0) {
			selected=i+1;
			break;
		}
	}
	debug(selected);
	for (int i=0;i<topics.size();i++) {
		if (selected==topics[i]&&visited.count(i)==0) {
			ans.push_back(i);
			search(i,adj,topics);
		}
	}
}*/

int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	vector <int> adj[n];
	vector <int> topics(n);
	for (int i=0;i<m;i++) {
		int u,v;
		scanf("%d %d",&u,&v);
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);	
	}
	for (int i=0;i<n;i++) {
		scanf("%d",&topics[i]);
	}
	int first;
	for (int i=0;i<n;i++) {
		if (topics[i]==1) {
			first=i;
			break;
		}
	}
	bool possible =search(first,adj,topics,true);
	if (!possible)
		printf("-1\n");
	else {
		for (int i=0;i<n;i++) {
			printf("%d ",ans[i]+1);
		}
		printf("\n");
	}
}