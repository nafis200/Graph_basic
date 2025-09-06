#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 9;
int par[N];
int group_size[N];

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
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main()
{

    int n;
    cin >> n;
    memset(par, -1, sizeof(par));
    for (int i = 0; i < N; i++)
    {
        group_size[i] = 1;
    }

    int count = 0;
    vector<pair<int, int>> rm;
    vector<pair<int, int>> create;

    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        int leader1 = find(a);
        int leader2 = find(b);
        if (leader1 == leader2)
        {
            count++;
            rm.push_back({a, b});
        }
        else
        {
            dsu_union(a, b);
        }
    }

    for (int i = 2; i <= n; i++)
    {
        int leader1 = find(1);
        int leader2 = find(i);
        if (leader1 != leader2)
        {
            create.push_back({1, i});
            dsu_union(1, i);
        }
    } 

    cout << count << "\n";

    for(int i = 0; i < count; i++){
        cout << rm[i].first << " " << rm[i].second << " " << create[i].first << " " << create[i].second << "\n";
    }
    
  
}