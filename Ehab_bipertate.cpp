#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int col[N];
bool vis[N];
vector<int>g[N];
void dfs(int u){
   vis[u] = true;
   for(auto v : g[u]){
     if(vis[v] == false){
        col[v] = col[u] ^ 1;
        dfs(v);
     }
   }
}
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(vis,false,sizeof(vis));
    memset(col,0,sizeof(col));
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    int blue = 0, red = 0;

    for(int i = 1; i <= n; i++){
        if(col[i] == 0){
            blue++;
        }
        else{
            red++;
        }
    }

    cout << ((1LL * blue * red) - (n- 1)) << "\n";

}