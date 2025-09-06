#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
bool vis[N], in_stack[N];
int par[N];
vector<int> cycle;
bool ok = false;

void dfs(int u) {
    vis[u] = true;
    in_stack[u] = true;

    for (int v : g[u]) {
        if (!vis[v]) {
            par[v] = u;
            dfs(v);
            if (ok) return;
        } else if (in_stack[v]) {
            ok = true;
            cycle.push_back(v);
            int cur = u;
            while (cur != v) {
                cycle.push_back(cur);
                cur = par[cur];
            }
            cycle.push_back(v);
            reverse(cycle.begin(), cycle.end());
            return;
        }
    }

    in_stack[u] = false;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            if (ok) break;
        }
    }

    if (!ok) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << cycle.size() << "\n";
        for (int x : cycle) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
