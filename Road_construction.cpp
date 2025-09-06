#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int par[N];
int group_size[N];
int cmp, mx;

int find(int node)
{

    if (par[node] == -1)
    {
        return node;
    }

    return par[node] = find(par[node]);
}

void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if (leader1 == leader2)
        return;

    if (group_size[leader1] >= group_size[leader2])
    {

        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
        mx = max(mx, group_size[leader1]);
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
        mx = max(mx, group_size[leader2]);
    }
    cmp--;
}

int main()
{

    int n, e;
    cin >> n >> e;
    cmp = n;
    mx = 1;

    memset(par, -1, sizeof(par));
    for (int i = 0; i < N; i++)
    {
        group_size[i] = 1;
    }

    for (int i = 1; i <= e; i++)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
        cout << cmp << " " << mx << "\n";
    }
}