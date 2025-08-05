#include <bits/stdc++.h>
using namespace std;

int main() {
    int edge;
    int Case = 1;
    while (cin >> edge && edge) {
        map<int, vector<int>> g;
        set<int> nodes;

        for (int i = 1; i <= edge; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            nodes.insert(u);
            nodes.insert(v);
        }

        int start, dist;
        while (cin >> start >> dist && !(start == 0 && dist == 0)) {
            map<int, int> dis;
            for (auto it : nodes) {
                dis[it] = 1e8;
            }

            queue<int> q;
            if (nodes.count(start)) {
                q.push(start);
                dis[start] = 0;
            }

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (auto v : g[u]) {
                    if (dis[u] + 1 < dis[v]) {
                        dis[v] = dis[u] + 1;
                        q.push(v);
                    }
                }
            }

            int ans = 0;
            for (auto it : nodes) {
                if (dis[it] > dist) ans++;
            }

            cout << "Case " << Case++ << ": " << ans 
                 << " nodes not reachable from node " << start 
                 << " with TTL = " << dist << "." << endl;
        }
    }

    return 0;
}
