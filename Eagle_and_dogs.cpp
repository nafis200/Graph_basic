#include<bits/stdc++.h> 
using namespace std; 
const int N = 3e5 + 4; 
const int inf = 1e9; 
int n; 
vector<pair<int,int>>g[N]; 
int bfs(int s, vector<long long> &d){ 
    d.resize(n + 1); 
    vector<bool>vis(n+1, false); 
    d[s] = 0; 
    queue<int>q; 
    q.push(s); 
    vis[s] =true; 
    while(!q.empty()){ 
        int u = q.front(); 
        q.pop(); 
        for(auto it : g[u]){ 
            if(!vis[it.first]){ 
                d[it.first] = d[u] + it.second; 
                vis[it.first] = true; 
                q.push(it.first); 
            } 
        } 
    } 
    int mx = 0, farthest = 0; 
    farthest = max_element(d.begin()+1, d.end()) - d.begin(); 
    return farthest; 
} 
int main(){ 
   int t , cs = 0; 
   cin >> t; 
   while(t--){ 
        cin >> n; 
       for(int i = 1; i < n; i++){ 
        int u, v, w; 
         cin >> u >> v >> w; 
         g[u].push_back({v, w}); 
         g[v].push_back({u, w}); 
       } 
       vector<long long>ds; 
       vector<long long>de; 
       int s = bfs(1, ds); 
       int e = bfs(s, ds); 
       int x =  bfs(e, de); 
       for(int i = 1; i <= n; i++){ 
        cout << max(ds[i], de[i]) << " "; 
       } 
        cout << "\n"; 
       for(int i = 1; i <= n; i++){ 
        g[i].clear(); 
       } 
 
   } 
} 