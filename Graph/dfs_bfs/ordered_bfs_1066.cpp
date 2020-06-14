#include <bits/stdc++.h>
using namespace std;
int n;

int dist[15][15];
int visited[15][15];
vector<string> graph;

int xd[8] = { -1, 1,  0, 0 };
int yd[8] = {  0, 0, -1, 1};

map<char, pair<int, int> >m;

void CLEAR() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            visited[i][j] = 0;
            dist[i][j] = 0;
        }
    }
}

void bfs(int sx, int sy, int dx, int dy) {
    queue< pair<int, int> >q;

    q.push(make_pair(sx, sy));
    visited[sx][sy] = 1;
    dist[sx][sy] = 0;

    while (!q.empty()) {
        pair<int, int> f = q.front();
        q.pop();

        int fx = f.first;
        int fy = f.second;


        for (int i = 0; i < 4; i++) {
            int tox = fx + xd[i];
            int toy = fy + yd[i];

            if (tox >= 0 && tox < n && toy >= 0 && toy < n && graph[tox][toy] != '#' && !visited[tox][toy] ) {

                if (graph[tox][toy] >= 'A' && graph[tox][toy] <= 'Z') {
                    if (graph[tox][toy] < graph[sx][sy]) {
                        dist[tox][toy] = dist[fx][fy] + 1;
                        visited[tox][toy] = 1;
                        q.push(make_pair(tox, toy));
                    }
                } else {
                     dist[tox][toy] = dist[fx][fy] + 1;
                        visited[tox][toy] = 1;
                        q.push(make_pair(tox, toy));
                    
                }

            }
        }

    }


}

int main()
{
    int t;
    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++) {
        scanf("%d", &n);

        graph.clear(); // clearing the grid
        m.clear(); // cleraing previous test case good position

        string a;
        for (int i = 0; i < n; i++) {
            cin >> a;
            graph.push_back(a);
        }

        int letter_counter = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] != '.' && graph[i][j] !='#') {
                    m[graph[i][j]] = make_pair(i, j);
                    letter_counter++;
                }
            }
        }
        int ans = 0;
        bool flag = true;

        for (int i = 0; i < letter_counter-1; i++) {
            CLEAR(); // clearing previous distance and visited
            flag = true;
            char s = char(65+i);

            int sx = m[s].first;
            int sy = m[s].second;

            char d = char(s + 1);
            int dx = m[d].first;
            int dy = m[d].second;
            
            bfs(sx, sy, dx, dy);

            if (!visited[dx][dy]) {
                printf("Case %d: Impossible\n", cs);
                flag = false;
                break;
            }
            ans += dist[dx][dy];
        }
        if (flag) {
            printf("Case %d: %d\n", cs, ans);
        }
    }

    return 0;
}

