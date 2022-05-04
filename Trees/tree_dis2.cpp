#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define N 200005
 
int n, m, k, x;
 
vector<int> adj[N];
int S[N];
int in[N];
int out[N];
 
void dfs_in(int u,int p)
{
	S[u] = 1;
	
	for (int v: adj[u]) {
		if (v != p) {
			dfs_in(v, u);
			S[u] += S[v];
			in[u] += in[v] + S[v];
		}
	}	
}
 
void dfs_out(int u, int p) {
	int store = 0;
	for(int v: adj[u]) {
		if(v != p)
		store += in[v] + S[v]*2;
	}
 
	for (int v : adj[u]) {
		if (v != p) {
			out[v] = (out[u] + 1*(n-S[u]+1)) + (store - (in[v] + S[v] * 2));
			dfs_out(v, u);
		}
	}
}
 
signed main() {
	int u,v;
 
	cin >> n;
	for(int i = 0; i < n-1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs_in(1, 0);
	dfs_out(1, 0);
 
	for(int i = 1; i <= n ; i++) 
		cout << in[i] + out[i] << " ";	
}