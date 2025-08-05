#include<bits/stdc++.h>
using namespace std;

int d[105], f[105];
vector<int> g[105];
bool vis[105];
int timer;

void dfs(int u) {
    vis[u] = true;
    timer++;
    d[u] = timer;
    for (auto v : g[u]) {
        if (vis[v] == false) {
            dfs(v);
        }
    }
    timer++;
    f[u] = timer;
}

int main() {
    memset(d, 0, sizeof(d));
    memset(f, 0, sizeof(f));
    memset(vis, false, sizeof(vis));
    timer = 0;

    int n;
    cin >> n;
    int n1 = n;

    while (n--) {
        int u, t;
        cin >> u >> t;
        while (t--) {
            int v;
            cin >> v;
            g[u].push_back(v);
        }
    }

    for (int u = 1; u <= n1; u++) { 
        sort(g[u].begin(), g[u].end());
    }

    for (int i = 1; i <= n1; i++) {
        if (!vis[i]) { 
            dfs(i);
        }
    }

    for (int i = 1; i <= n1; i++) {
        cout << i << " " << d[i] << " " << f[i] << "\n";
    }
}
