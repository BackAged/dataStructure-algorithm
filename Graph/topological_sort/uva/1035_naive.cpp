#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m;

vector<int> graph[N];
int visited[N];
vector<int>ans;

void dfs(int s) {
    visited[s] = true;

    for (int i = 0; i < graph[s].size(); i++) {
        int to = graph[s][i];
        if (!visited[to])
            dfs(to);
    }
    ans.push_back(s);

}


void topological_sort() {
    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

int main()
{

    while(scanf("%d %d", &n, &m) && (n || m) ) {
        for (int i = 0; i < N; i++ ) {
            graph[i].clear();
        }
        memset(visited, 0, sizeof visited);
        ans.clear();

        int a, b;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            graph[a].push_back(b);
        }

        topological_sort();

        for (int i = 0; i < n-1; i++)
            cout << ans[i] << " ";
        cout << ans[n-1] << endl;
    }
    return 0;
}
