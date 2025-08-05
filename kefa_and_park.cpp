#include <bits/stdc++.h>
using namespace std;
map<int, vector<int>> g;
map<int, bool> vis;
set<int> nodes;
const int N = 1e5 + 9;
int cats[N];
int consecutive[N];
int ans;
int n, m;
// void dfs(int u)
// {
//     vis[u] = true;
//     bool ok = true;
//     if (consecutive[u] > m)
//     {
//         return;
//     }
//     for (auto it : g[u])
//     {
//         if (vis[it] == false)
//         {
//             ok = false;
//             if(cats[it]){
//                 consecutive[it] = consecutive[u] + cats[it];
//             }
//             dfs(it);
//         }
//     }
//     if (ok)
//     {
//         ans++;
//     }
// }
void dfs(int u, int p){
    if(cats[u]){
        consecutive[u] = consecutive[p] + 1;
    }
    vis[u] = true;
    bool ok = true;
    if(consecutive[u] > m){
        return;
    }
    for(auto it : g[u]){
        if(vis[it] == false){
            ok = false;
            dfs(it, u);
        }
    }
    if(ok){
        ans++;
    }
}
int main()
{
    memset(cats, 0, sizeof(cats));
    memset(consecutive, 0, sizeof(consecutive));
    ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> cats[i];
    }

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        nodes.insert(u);
        nodes.insert(v);
    }
    for (auto it : nodes)
    {
        vis[it] = false;
    }
    consecutive[1] = cats[1];
    dfs(1,0);
    cout << ans << "\n";
}