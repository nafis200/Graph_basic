#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
bool vis[N];
int col[N];
vector<int>g[N];
bool ok;
void dfs(int u){
    vis[u] = true;
    for(auto v : g[u]){
        if(vis[v] == false){
            col[v] = col[u] ^ 1;
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
   int t; cin >> t;
   int Case = 0;
   while(t--){
    memset(col,0,sizeof(col));
    memset(vis,false,sizeof(vis));
    ok = true;
    int v, e;
    cin >> v >> e;
    while(e--){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= v; i++){
         if(vis[i] == false){
            dfs(i);
         }
    }
    cout << "Scenario #" << ++Case << ":\n";
    if(!ok){
       cout << "Suspicious bugs found!\n";
    }
    else{
        cout << "No suspicious bugs found!\n";
    }
    for(int i = 0; i <= v + 10; i++){
        g[i].clear();
    }
   }
}