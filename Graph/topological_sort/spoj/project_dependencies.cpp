#include <bits/stdc++.h>
using namespace std;

set<int>nodes;

vector<int>graphs[105];
vector<int>res;
int indegree[105];



int main()
{
    int n, m, u, h, a;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> u >> h;
        for (int j = 0; j < h; j++) {
            cin >> a;
            graphs[a].push_back(u);
            indegree[u]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0)
            nodes.insert(i);
    }

    while (!nodes.empty()) {
        int f = *nodes.begin();
        nodes.erase(nodes.begin());


        res.push_back(f);

        for (int i = 0; i < graphs[f].size(); i++) {
            int to = graphs[f][i];
            indegree[to]--;
            if (!indegree[to])
                nodes.insert(to);
        }

    }

    for (int i = 0; i < res.size()-1; i++) {
        cout << res[i] << " ";
    }
    cout << res[res.size()-1];
}
