#include<bits/stdc++.h> 
using namespace std; 
 const int N = 1e5 + 9; 
 vector<int>g[N]; 
 bool vis[N]; 
 int dis[N]; 
 int par[N]; 
 int main(){ 
   memset(vis, false, sizeof(vis)); 
   memset(dis, 0, sizeof(dis)); 
   int n, m; cin >> n >> m; 
   while(m--){ 
       int u, v; cin >> u >> v; 
       g[u].push_back(v); 
       g[v].push_back(u); 
   } 
   queue<int>q; 
   q.push(1); 
   dis[1] = 0; 
   vis[1] = true; 
   par[1] = 0; 
   while(!q.empty()){ 
      int u = q.front(); 
      cout << u << " "; 
      q.pop(); 
      for(auto v : g[u]){ 
         if(!vis[v]){ 
            q.push(v); 
            vis[v] = true; 
            dis[v] = dis[u] + 1; // koto stage ache 
            par[v] = u; // graph er tracking path 
         } 
      } 
   } 
   cout << "\n"; 
   for(int i = 1; i <=n; i++) 
   cout << dis[i] << " "; 
   cout << "\n"; 
   int v = 3; 
   cout << 1 << " "; 
   while(v != 1){ 
      cout << v << " "; 
      v = par[v]; 
   } 
    
 }