/*
    a simple bi coloring problem
    for each disjoint connected components taking color with max number and adding them all

*/

#include<bits/stdc++.h>
using namespace std;

vector<int>graph[100005];

int color[100005];

vector<pair<long long int ,long long int> > groups;
long long int lycans = 0, vampires = 0;
set<int>nodes;

int n;

void bfs() {
    set<int>::iterator it;
    for (it = nodes.begin(); it != nodes.end(); ++it) {
        if (color[*it] == 0) {
            lycans = 0;
            vampires = 0;

            queue<int>q;
            q.push(*it);
            color[*it] = 1;
            lycans++;

            while (!q.empty()) {
                int s = q.front();
                q.pop();
                int si = graph[s].size();
                for (int i = 0; i < si; i++) {
                    int to = graph[s][i];
                    if (color[to] == 0) {
                        if (color[s] == 1) {
                            color[to] = 2;
                            vampires++;
                        } else {
                            color[to] = 1;
                            lycans++;
                        }
                        q.push(to);
                    }
                }
            }
            groups.push_back(make_pair(lycans, vampires));
        }
    }
}

int main () {
    int t;
    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++) {

        memset(color, 0, sizeof color);
        for (int i = 0; i < 100005; i++) {
            graph[i].clear();
        }
        groups.clear();
        nodes.clear();

        cin >> n;
        int a, b;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
            nodes.insert(a);
            nodes.insert(b);
        }

        bfs();
        long long int total = 0;
        for (int i = 0; i < groups.size(); i++) {
            total += max(groups[i].first, groups[i].second);
        }

        printf("Case %d: %lld\n", cs, total);

    }




}
