include<bits/stdc++.h> 
using namespace std; 
 const int N = 1e5 + 9; 
 vector<int>g[N]; 
 bool vis[N]; 
 int col[N]; 
 bool ok; 
 void dfs(int u){ 
   vis[u] = true; 
   for(auto v : g[u]){ 
      if(!vis[v]){ 
         col[v] = col[u]  ^ 1; 
         dfs(v); 
      } 
      else{ 
         if(col[v] == col[u]){ 
            ok = false; 
         } 
      } 
   } 
 } 
 int main(){ 
   memset(vis, false, sizeof(vis)); 
   memset(col, 0, sizeof(col)); 
   int n, m; cin >> n >> m; 
   ok = true; 
   while(m--){ 
       int u, v; cin >> u >> v; 
       g[u].push_back(v); 
       g[v].push_back(u); 
   } 
   for(int i = 1; i <= n; i++){ 
      if(!vis[i]){ 
         dfs(i); 
      } 
   } 
   if(ok){ 
      cout << "YES" << "\n"; 
   } 
   else{ 
      cout << "NO" << "\n"; 
   } 
 } 