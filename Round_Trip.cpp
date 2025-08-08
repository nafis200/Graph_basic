#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
bool vis[N];
vector<int> g[N];
vector<int> cycle;
bool ok;
int par[N];
void dfs(int u, int p)
{
    if(ok){
        return;
    }
    vis[u] = true;
    par[u] = p;
    for (auto v : g[u])
    {
        if(ok){
            return;
        }
        if (vis[v] == false)
        {
            dfs(v, u);
        }
        else if (vis[v] == true and v != p)
        {
            int x = v;
            ok = true;
            cycle.push_back(v);
             while (u != v)
            {
                cycle.push_back(u);
                u = par[u];
            }
            cycle.push_back(x);
            return;
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    memset(vis, false, sizeof(vis));
    ok = false;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
   for(int i = 1; i <= n; i++){ 
        if(!vis[i]){ 
            dfs(i, 0); 
        } 
    } 
    if(!ok){ 
        cout << "IMPOSSIBLE" << endl;
    } 
    else{ 
        cout << cycle.size() << "\n"; 
        for(auto it : cycle){ 
            cout << it << " ";  
        } 
    } 
}