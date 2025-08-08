#include<bits/stdc++.h> 
using namespace std; 
const int N = 1e5 + 9; 
vector<int>g[N]; 
bool vis[N]; 
void dfs(int i){ 
    vis[i] = true; 
    for(auto v : g[i]){ 
        if(!vis[v]) 
        dfs(v); 
    } 
} 
int main(){ 
    int n, m; 
    cin >> n >> m; 
    while(m--){ 
        int u, v; cin >> u >> v; 
        g[u].push_back(v); 
        g[v].push_back(u); 
    } 
    vector<int>connect; 
    for(int i = 1; i <= n; i++){ 
        if(!vis[i]){ 
            connect.push_back(i); 
            dfs(i); 
        } 
    } 
    cout << connect.size() - 1 << "\n"; 
    for(int i = 1; i < connect.size(); i++) 
    cout << connect[i-1] << " " << connect[i] << "\n"; 
 
} 