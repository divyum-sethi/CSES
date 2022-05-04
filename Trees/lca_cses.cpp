#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<long,long> pl;
typedef pair<ll,ll> pll;
typedef vector<long> vl;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<vl> vvl;
typedef vector<vb> vvb;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef vector<string> vs;

#define FOR(i,a,b) for(long long i=a;i<b;++i)
#define REV(i,a,b) for(long long i=a;i>=b;i--)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define tc ll t;cin>>t;while(t--)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define coutv(v) for(auto it: (v))cout<<it<<" ";newl;
#define cout2d(v) for(auto it: (v)) {for(auto j:it) cout<<j<<" ";newl;}
#define cinv(v,n) vll (v)(n);FOR(i,0,(n)){cin>>v[i];}
#define cinvg(v,n) (v).resize(n);FOR(i,0,(n)){cin>>v[i];}
#define cin2d(v,n,m) vvll (v)(n,vll(m,0));FOR(i,0,n){FOR(j,0,m){cin>>v[i][j];}}
#define cin2dg(v,n,m) (v).resize(n,vll(m));FOR(i,0,n){FOR(j,0,m){cin>>v[i][j];}}
#define newl cout<<"\n"
#define mod 1000000007


int const lgmax = 20;
int N = 2e5;
int main() {
	int n,q;
	cin>>n>>q;
	vector<vector<int>> far(lgmax+1,vector<int>(N+1));
	vector<int> level(N+1,0);
	for(int i =2;i<=n;i++) {
		cin>>far[0][i];
	}
	for(int h =1;h<=lgmax;h++) {
		for(int i =1;i<=n;i++) {
			far[h][i]=far[h-1][far[h-1][i]];
		}
	}
	for(int i =2;i<=n;i++) {
		level[i]=level[far[0][i]]+1;
	}
	for(int i =1;i<=q;i++) {
		int x,y;
		cin>>x>>y;
		if(level[x]<level[y]) {
			swap(x,y);
		}
		for(int h=lgmax;h>=0;h--) {
			if(level[y]+(1<<h)<=level[x]) {
				x=far[h][x];
			}

		}
		if(x==y) {
			cout<<x<<endl;
			continue;
		}
		for(int h =lgmax;h>=0;h--) {
			if(far[h][x]!=far[h][y]) {
				x=far[h][x];
				y=far[h][y];
			}
		}
		cout<<far[0][x]<<endl;
	}

}