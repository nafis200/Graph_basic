#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<int> g[N];
bool vis[N];
int money[N];
int person = 0;
int tot = 0;
int n, m;
void dfs(int u)
{
    ++person;
    tot = tot + money[u];
    vis[u] = true;
    for (auto v : g[u])
    {
        if (vis[v] == false)
        {
            dfs(v);
        }
    }
}

void solve()
{
    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            tot = 0;
            person = 0;
            dfs(i);
            if (tot % person == 0)
            {
                st.insert(tot / person);
            }
            else
            {
                cout << "No\n";
                return;
            }
        }
    }
    if (st.size() == 1)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}
int main()
{
    int t;
    cin >> t;
    int cs = 0;
    while (t--)
    {
        cout << "Case " << ++cs << ": ";
        memset(vis, false, sizeof(false));
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> money[i];
        }
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        solve();
        for(int i = 1; i <= n; i++){
            g[i].clear();
            vis[i] = false;
        }
    }
}


