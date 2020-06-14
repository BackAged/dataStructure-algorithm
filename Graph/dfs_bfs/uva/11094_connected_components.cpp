#include<bits/stdc++.h>
using namespace std;

int n, m, homex, homey;

vector<string>graph;
int visited[25][25];

int max_continent = 0, l = 0;
char land;


void dfs(int r, int c) {
    if (r < 0 || r >= n) // x overflow
        return;
    else if (c >= m)  // right left
        c = 0;
    else if (c < 0)  //  left to right connectivity
        c = m - 1;
    if (graph[r][c] != land || visited[r][c] == 1)
        return;

    visited[r][c] = 1;
    l++;

    dfs(r+1, c);
    dfs(r, c+1);
    dfs(r-1, c);
    dfs(r, c-1);
}


int main () {

    while (cin >> n >> m && n && m) {

        graph.clear();
        memset(visited, 0, sizeof(visited)); // cleared memory


        string a;

        for (int i = 0; i < n; i++) {
            cin >> a;
            graph.push_back(a);
        } // input

        cin >> homex >> homey; // home position
        land = graph[homex][homey];


        dfs(homex, homey); //majeed current continent


        max_continent = 0;


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && graph[i][j] == land) {
                    l = 0;
                    dfs(i, j);
                    max_continent = max(max_continent, l);
                    
                }
            }
        }

        cout << max_continent << endl;


    }

    return 0;
}
