#include <bits/stdc++.h>
using namespace std;
const int N = 30005;
vector<pair<int, int>> g[N];
int dis[N];
bool vis[N];

void dfs(int u)
{
    vis[u] = true;
    for (auto v : g[u])
    {
        if (vis[v.first] == false)
        {
            dis[v.first] = v.second + dis[u];
            dfs(v.first);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    int Case = 0;
    while (t--)
    {
        memset(vis, false, sizeof(vis));
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            g[i].clear();
        }
        memset(dis, 0, sizeof(dis));

        for (int i = 1; i < n; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        dfs(1);
        int s = 0, mx = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dis[i] > mx)
            {
                mx = dis[i];
                s = i;
            }
        }
        memset(dis, 0, sizeof(dis));
        memset(vis, false, sizeof(vis));
        dfs(s);
        for (int i = 1; i <= n; i++)
        {
            if (dis[i] > mx)
            {
                mx = dis[i];
                s = i;
            }
        }
        cout << "Case " << ++Case << ": " << mx << "\n";
    }
}