#include <bits/stdc++.h>
using namespace std;

struct soldier {
	int city, strength;
};

vector<vector<int>> adj;
int n, r, m;
vector<bool> visited;
vector<soldier> soldiers;

void bfs(soldier s) {
	vector<bool> visitedByThis(n);
	int start = s.city;
	int strength = s.strength;
	queue<int> q;
	q.push(start);
	visitedByThis[start] = true;
	visited[start] = true;
	for(int i = 0; i < strength; ++i) {
		int size = q.size();
		for(int j = 0; j < size; ++j) {
			int front = q.front();
			q.pop();
			for(int a : adj[front]) {
				if(!visitedByThis[a]) {
					visited[a] = true;
					visitedByThis[a] = true;
					q.push(a);
				}
			}
		}
	}

}


void solve() {
	adj.clear();
	soldiers.clear();
	cin>>n>>r>>m;
	adj = vector<vector<int>>(n); 
	visited = vector<bool>(n);
	for(int i = 0; i < r; ++i) {
		int a, b;
		cin>>a>>b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 0; i < m; ++i) {
		int city, strength;
		cin>>city>>strength;
		soldiers.push_back({city - 1, strength});
	}
	for(soldier s : soldiers) {
		bfs(s);
	}
	for(bool isVisit : visited) {
		if(!isVisit) {
			cout<<"No\n";
			return;
		}
	}
	cout<<"Yes\n";
}


int main() {
	int t;
	cin>>t;
	while(t--) {
		solve();
	}
}