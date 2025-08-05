#include<bits/stdc++.h>
using namespace std;
const int N = 105;
vector<pair<int,int>>g[N];
bool vis[N];
int total_cost;
int path_cost;
void dfs(int u, int p){
  vis[u] = true;
  for(auto v : g[u]){
     if(vis[v.first] == false){
        path_cost += v.second;
        dfs(v.first, u);
     }
    else if(v.first == 1 && p != 1){
        path_cost += v.second;
    }
  }
}
int main(){
    int n; cin >> n;
    total_cost = 0;
    path_cost = 0;
    memset(vis,false,sizeof(vis));
    for(int i = 1; i <= n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v,0});
        g[v].push_back({u,w});
        total_cost += w;
    }
    dfs(1, 0);
    cout << min(path_cost, total_cost - path_cost) << "\n";
}