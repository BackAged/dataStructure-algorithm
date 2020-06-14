/*
    => simple graph problem
    => we have to go every city from each person house
    => then have to check how many times each city has been visited by different person
    => if a city was visited by all person that increment the anser

*/

#include<bits/stdc++.h>
using namespace std;
int k, n, m, u, v;
const int MAXN = 1e3 + 10;

vector<int> graph[MAXN];
int visited_city[MAXN];
int temp_visited[MAXN];
int city_house[105];

void bfs(int person) {
    int sc = city_house[person];

    queue<int>q;
    q.push(sc);
    temp_visited[sc] = 1;
    visited_city[sc]++;

    while (!q.empty()) {
        int f = q.front();
        q.pop();

        for (int i = 0; i < graph[f].size(); i++) {
            int to = graph[f][i];

            if (!temp_visited[to]) {
                q.push(to);
                temp_visited[to] = 1;
                visited_city[to]++;
            }
        }
    }

}

void CLEAR() {
    memset(visited_city, 0, sizeof visited_city);
    for (int i = 0; i < MAXN; i++) {
        graph[i].clear();
    }
    memset(temp_visited, 0, sizeof visited_city);
    memset(city_house, 0, sizeof city_house);
}


int main () {
    int t;
    cin >> t;

    for (int cs = 1; cs <= t; cs++) {

        CLEAR();

        scanf("%d %d %d", &k, &n, &m);

        for (int i = 1; i <= k; i++) {
            scanf("%d", &city_house[i]);
        }

        for (int i = 1; i <= m; i++) {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
        }

        for (int i = 1; i <= n; i++) {
            bfs(i);
            memset(temp_visited, 0, sizeof temp_visited);
        }
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (visited_city[i] >= k) {
                ans++;
            }
        }

        printf("Case %d: %d\n", cs, ans);

    }



}
