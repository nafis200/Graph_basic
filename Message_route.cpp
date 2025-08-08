#include<bits/stdc++.h> 
using namespace std; 
const int inf = 1e9; 
const int N = 1e5 + 9; 
vector<int>g[N]; 
int par[N]; 
int main(){ 
    int n, m; cin >> n >> m; 
    for(int i = 1; i <= m; i++){ 
        int u, v; cin >> u >> v; 
            g[u].push_back(v); 
            g[v].push_back(u); 
    } 
    queue<int>q; 
    vector<int>d(n+1, inf); 
    q.push(1); 
    d[1] = 0; 
    par[1] = 0; 
    while(!q.empty()){ 
        int x = q.front(); 
        q.pop(); 
        for(auto it : g[x]){ 
            if(d[x] + 1 < d[it]){ 
               d[it] = d[x] + 1; 
               q.push(it); 
               par[it] = x; 
            } 
        } 
    } 
   if(d[n] == inf){ 
    cout << "IMPOSSIBLE\n";  
   } 
   else 
   { 
      cout << d[n] + 1 << "\n"; 
      vector<int>path; 
      int u = n; 
      while(u){ 
         path.push_back(u); 
         u = par[u]; 
      } 
      reverse(path.begin(),path.end()); 
      for(auto it : path){ 
        cout << it << " "; 
      } 
   } 
} 