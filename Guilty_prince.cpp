#include<bits/stdc++.h>
using namespace std;

const int N = 50;
bool vis[N][N];
int n, m;
string g[N];
int visit;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool isValid(int i, int j) {
    return (i >= 0 && i < m && j >= 0 && j < n);
}

void dfs(int i, int j) {
    vis[i][j] = true;
    visit++;

    for(int k = 0; k < 4; k++) {
        int nxt_i = i + dx[k];
        int nxt_j = j + dy[k];

        if(isValid(nxt_i, nxt_j) && g[nxt_i][nxt_j] == '.' && !vis[nxt_i][nxt_j]) {
            dfs(nxt_i, nxt_j);
        }
    }
}

int main() {
    int t;
    cin >> t;
    int Case = 0;

    while(t--) {
        memset(vis, false, sizeof(vis));
        visit = 0;

        cin >> n >> m; 
        for(int i = 0; i < m; i++) {
            cin >> g[i];
        }

        int start_i = 0, start_j = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(g[i][j] == '@') {
                    start_i = i;
                    start_j = j;
                }
            }
        }

        dfs(start_i, start_j);

        cout << "Case " << ++Case << ": " << visit << "\n";
    }

    return 0;
}
