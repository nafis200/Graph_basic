#include<bits/stdc++.h> 
using namespace std; 
const int N = 1e5 + 9; 
bool vis[N]; 
bool found; 
int par[N]; 
vector<int>cycle,g[N]; 
void dfs(int u, int p){ 
    if(found){ 
        true; 
    } 
    vis[u] = true; 
    par[u] = p; 
    for(auto v : g[u]){ 
        if(found){ 
            return; 
        } 
        if(!vis[v]){ 
            dfs(v,u); 
        } 
        else if(v != p){ 
            found = true; 
            int st = u; 
            while(u != v){ 
                cycle.push_back(u); 
                u = par[u]; 
            } 
            cycle.push_back(v); 
            cycle.push_back(st); 
            return; 
        } 
    } 
} 
int main(){ 
    int n, m; cin >> n >> m; 
    for(int i = 1; i <= m; i++){ 
        int u, v; cin >> u >> v; 
        g[u].push_back(v); 
        g[v].push_back(u); 
    } 
    for(int i = 1; i <= n; i++){ 
        vis[i] = false; 
    } 
    for(int i = 1; i <= n; i++){ 
        if(!vis[i]){ 
            dfs(i, 0); 
        } 
    } 
    if(!found){ 
        cout << "IMPOSSIBLE" << endl;
    } 
    else{ 
        cout << cycle.size() << "\n"; 
        for(auto it : cycle){ 
            cout << it << " ";  
        } 
    } 
} 