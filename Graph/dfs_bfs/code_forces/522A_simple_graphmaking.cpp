#include <bits/stdc++.h>
using namespace std;

map<string , int> m;

vector<int>graphs[205];
int visited[205];
int max_level = -1;

void dfs(int s, int level) {
    visited[s] = true;
    for (int i = 0; i < graphs[s].size(); i++) {
        if (!visited[ graphs[s][i] ]) {
            max_level = max(max_level, level+1);
            dfs(graphs[s][i], level+1);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    string name1, nothing, name2;
    int node = 1;
    m["polycarp"] = 1;


    for (int i = 0; i < n; i++) {
        cin >> name1 >> nothing >> name2;

        for (int i = 0; i < name1.size(); i++) {
            name1[i] = tolower(name1[i]);
        }
        for (int i = 0; i < name2.size(); i++) {
            name2[i] = tolower(name2[i]);
        }

        if (!m[name1]) {
            m[name1] = ++node;
        }
        if (!m[name2]) {
            m[name2] = ++node;
        }

        graphs[m[name2]].push_back(m[name1]);

    }

    dfs(1, 1);

    cout << max_level << endl;

    return 0;
}

