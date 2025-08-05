#include<bits/stdc++.h>
using namespace std;
vector<int>g[205];
bool vis[205];
int col[205];
bool ok;

void dfs(int u){
    vis[u] = true;
    for(auto v: g[u]){
        if(vis[v] == false){
            col[v] = col[u] ^ 1;
            dfs(v);
        }
        else{
            if(col[v] == col[u]){
                ok = false;
                return;
            }
        }
    }
}

int main(){
    int n,v;
    while((cin >> n >> v)){
        if(n == 0){
            break;
        }
        for(int i = 0; i < 201; i++){
            g[i].clear();
        }
        memset(vis,false,sizeof(vis));
        memset(col,0,sizeof(col));
        ok = true;
        for(int i = 0; i < v; i++){
            int u, x;
            cin >> u >> x;
            g[u].push_back(x);
            g[x].push_back(u);
        }
        dfs(0);
        if(ok){
            cout << "BICOLORABLE\n";
        }
        else{
            cout << "NOTBICOLORABLE\n";
        }

    }
}