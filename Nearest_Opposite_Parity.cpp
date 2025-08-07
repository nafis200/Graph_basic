#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9, inf = 1e9;
vector<int> g[N];
int ans[N], a[N];
int n;
void solve(vector<int> even, vector<int> odd)
{
    vector<int> d(n + 5, inf);
    queue<int>q;
    for (auto it : even)
    {
        q.push(it);
        d[it] = 0;
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto v : g[x])
        {
            if (d[v] > d[x] + 1)
            {
                d[v] = d[x] + 1;
                q.push(v);
            }
        }
    }
    for (auto u : odd)
    {
        ans[u] = d[u];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> even, odd;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 1)
        {
            odd.push_back(i);
        }
        else
        {
            even.push_back(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int j = i - a[i];
        if (j >= 1)
            g[j].push_back(i);
        j = i + a[i];
        if (j <= n)
            g[j].push_back(i);
    }
    solve(even, odd);
    solve(odd, even);
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == inf)
            ans[i] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
}