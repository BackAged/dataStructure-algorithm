#include <bits/stdc++.h>
using namespace std;


vector<int>graphs[1005];
int indegree[1005];
int level[1005];
priority_queue<pair<int, int> ,vector< pair<int, int> >,greater< pair<int, int> > > ranked;

int main()
{
    int n, m, u, h, a;
    int t;
    cin >> t;

    for (int cs = 1; cs <= t; cs++) {
        // clearing previous
        for (int i = 0; i < 105; i++) {
            graphs[i].clear();
        }
        memset(indegree, 0, sizeof indegree);


        cin >> n >> m;

        // forming graph
        for (int i = 0; i < m; i++) {
            cin >> u >> a;
                graphs[a].push_back(u);
                indegree[u]++;

        }

        queue<int>q;

        // first bosses
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                level[i] = 1;
                ranked.push( make_pair(1, i)); // pushing it to the rank
            }
        }

        // running bfs
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            for (int i = 0; i < graphs[f].size(); i++) {
                int to = graphs[f][i];
                --indegree[to];
                if (indegree[to] == 0) {
                    q.push(to);
                    level [to] = level[f] + 1;
                    ranked.push( make_pair(level[to], to) );

                }
            }

        }
        cout << "Scenario #" << cs << ":" << endl;

         while(!ranked.empty()){
            pair<int, int> top=ranked.top();
            printf("%d %d\n",top.first,top.second);
            ranked.pop();
        }

    }

}
