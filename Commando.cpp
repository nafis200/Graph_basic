
#include<bits/stdc++.h>
using namespace std;
const int N = 105;
vector<int>g[N];
const int inf = 1e8 + 9;
vector<int>BFS(int i, int n){
     vector<int>d(n, inf);
     queue<int>q;
     q.push(i);
     d[i] = 0;
     while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto v : g[x]){
            if(d[v] > d[x] + 1){
                d[v] = d[x] + 1;
                q.push(v);
            }
        }
     }
     return d;
}
int main(){
    int t; cin >> t;
    int Case = 0;
    while(t--){
        int v,e; cin >> v >> e;
        while(e--){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
         int start, distination;
            cin >> start >> distination;

            auto ds = BFS(start, v);
            auto de = BFS(distination, v);
            int mx = -1e9;
            for(int i = 0; i <(int) ds.size(); i++){
                mx = max(mx, ds[i] + de[i]);

            }
            cout << "Case " << ++Case << ": ";
            cout << mx << "\n";
    }
}