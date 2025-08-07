#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }

        vector<bool> vis(n + 1, false);
        vector<vector<int>> g(n + 1); 
        vector<int> indeg(n + 1, 0); 

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            indeg[v]++;
        }

        vector<int> ans, z;
        for (int i = 1; i <= n; i++) {
            if (indeg[i] == 0) {
                z.push_back(i);
                vis[i] = true;
            }
        }

        while (ans.size() < n) {
            if (z.empty()) {
                break; 
            }
            int x = z.back();
            z.pop_back();
            ans.push_back(x);
            for (auto it : g[x]) {
                indeg[it]--;
                if (indeg[it] == 0 && !vis[it]) {
                    z.push_back(it);
                    vis[it] = true;
                }
            }
        }

        if (ans.size() == n) {
            for (auto it : ans) {
                cout << it << " ";
            }
            cout << "\n";
        } else {
            cout << "Dead lock\n";
        }
    }
    return 0;
}
