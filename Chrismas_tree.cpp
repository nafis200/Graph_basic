#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, m; cin >> n >> m;
    queue<long long>q;
    map<long long,long long>d;
    while(n--){
         long long x; cin >> x;
         q.push(x);
         d[x] = 0;
    }
    long long ans = 0;
    vector<long long>v;
    while(!q.empty() and m > 0){
           long long u = q.front();
           q.pop();
           if(d.find(u - 1) == d.end() and m > 0){
                d[u - 1] = d[u] + 1;
                q.push(u - 1);
                v.push_back(u - 1);
                m--;
           }
           if(d.find(u + 1) == d.end() and m > 0){
                d[u + 1] = d[u] + 1;
                q.push(u + 1);
                v.push_back(u + 1);
                m--;
           }
    }
    for(auto it : d){
        ans += it.second;
    }
    cout << ans << "\n";
    for(auto it : v){
        cout << it << " ";
    }
}