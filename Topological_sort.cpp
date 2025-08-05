#include<bits/stdc++.h> 
using namespace std; 
 const int N = 1e5 + 9; 
 vector<int>g[N]; 
 int indeg[N]; 
 bool vis[N]; 
 int main(){ 
   memset(vis, false, sizeof(vis)); 
   memset(indeg, 0, sizeof(indeg)); 
   int n, m; cin >> n >> m; 
   while(m--){ 
       int u, v; cin >> u >> v; 
       g[u].push_back(v); 
       indeg[v]++; 
   } 
   vector<int>ans; 
   while(ans.size() < n){ 
      int cur = 0; 
      for(int i = 1; i <= n; i++){ 
         if(indeg[i] == 0 && !vis[i]){ 
             cur = i; 
             vis[i] = true; 
             break; 
         } 
      } 
      ans.push_back(cur); 
      for(auto v : g[cur]){ 
         indeg[v]--; 
      } 
   } 
   for(auto x : ans){ 
      cout << x << " "; 
   } 
    
 } 



//  for cyclic 


#include<bits/stdc++.h> 
using namespace std; 
 const int N = 1e5 + 9; 
 vector<int>g[N]; 
 int indeg[N]; 
 bool vis[N]; 
 int main(){ 
   memset(vis, false, sizeof(vis)); 
   memset(indeg, 0, sizeof(indeg)); 
   int n, m; cin >> n >> m; 
   while(m--){ 
       int u, v; cin >> u >> v; 
       g[u].push_back(v); 
       indeg[v]++; 
   } 
   vector<int>ans; 
   while(ans.size() < n){ 
      int cur = 0; 
      for(int i = 1; i <= n; i++){ 
         if(indeg[i] == 0 && !vis[i]){ 
             cur = i; 
             vis[i] = true; 
             break; 
         } 
      } 
      if(cur == 0){ 
         cout << "impossible"<< "\n"; 
         return 0; 
      } 
      ans.push_back(cur); 
      for(auto v : g[cur]){ 
         indeg[v]--; 
      } 
   } 
   for(auto x : ans){ 
      cout << x << " "; 
   } 
    
 }



//  optimise

#include<bits/stdc++.h> 
using namespace std; 
 const int N = 1e5 + 9; 
 vector<int>g[N]; 
 int indeg[N]; 
 bool vis[N]; 
 int main(){ 
   memset(vis, false, sizeof(vis)); 
   memset(indeg, 0, sizeof(indeg)); 
   int n, m; cin >> n >> m; 
   while(m--){ 
       int u, v; cin >> u >> v; 
       g[u].push_back(v); 
       indeg[v]++; 
   } 
   vector<int>ans; 
   vector<int>z; 
   for(int i = 1; i <= n; i++){ 
      if(indeg[i] == 0){ 
         vis[i] = true; 
         z.push_back(i); 
      } 
   } 
   while(ans.size() < n){ 
      int cur = z.back(); 
      z.pop_back(); 
      ans.push_back(cur); 
      for(auto v : g[cur]){ 
         indeg[v]--; 
         if(!vis[v] && indeg[v] == 0){ 
            z.push_back(v); 
            vis[v] = true; 
         } 
      } 
   } 
   for(auto x : ans){ 
      cout << x << " "; 
   } 
    
 }