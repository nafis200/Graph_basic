#include<bits/stdc++.h>
using namespace std;
const int N = 10000 + 5;
bool vis[N];
int person[N];
vector<int>g[N];
int cnt[N];
void dfs(int u){
    vis[u] = true;
    cnt[u]++;
    for(auto v: g[u]){
        if(vis[v] == false){
            dfs(v);
        }
    }
}
int main(){
    int t; cin >> t;
    int Case = 0;
    while(t--){
        int k, n, m;
        cin >> k >> n >> m;
        for(int i = 0; i < k; i++){
            cin >> person[i];
        }
        memset(cnt, 0 , sizeof(cnt));
        memset(vis, false , sizeof(vis));
        while(m--){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
        }
       
        for(int i = 0; i < k; i++){
            for(int j = 1; j <= n; j++){
                vis[j] = false;
            }
            dfs(person[i]);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(cnt[i] == k){
                ans++;
            }
        }
        
        cout << "Case " << ": " << ans << "\n";
        for(int i = 1; i <= n; i++){
            g[i].clear();
            cnt[i] = 0;
            vis[i] = false;
            person[i] = 0;
        }
    }
}