/*
  => simple bfs shortest path as edge cost 1
  => main hints to see is that train or bus starts at 1, so if there is no train route 1 to n, there is a bus route 1 to n
  => 
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
vector<int>graphs[405];

int visited1[405];
int visited2[405];

int level1[405];
int level2[405];



void bfs() {
    queue<int>q;
    q.push(1);
    visited1[1] = 1;
    level1[1] = 0;
    
    while(!q.empty()) {
        int f = q.front();
        q.pop();
        
        for (int i = 0; i < graphs[f].size(); i++) {
            int to = graphs[f][i];
            
            if (!visited1[to]) {
                level1[to] = level1[f] + 1;
                visited1[to] = 1;
                q.push(to);
            }
        }
    }
}


void bfs2() {
    queue<int>q;
    q.push(1);
    visited2[1] = 1;
    level2[1] = 0;
    
    while(!q.empty()) {
        int f = q.front();
        q.pop();
        
        for (int i = 1; i <= n; i++) {
            if (i != f && find(graphs[f].begin(), graphs[f].end(), i) == graphs[f].end() ) {
                if (!visited2[i]) {
                    level2[i] = level2[f] + 1;
                    visited2[i] = 1;
                    q.push(i);
                }
            }
        }
    }
}


int main()
{
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graphs[a].push_back(b);
        graphs[b].push_back(a);
    }
    int bus, train;
    
    
    if (find(graphs[1].begin(), graphs[1].end(), n) != graphs[1].end()) {
        train = 1;
        // bus
        bfs2();
        if (visited2[n] == 0) {
            cout << -1 << endl;
            return 0;
        }
        bus = level2[n];
    } else {
        bus = 1;
        bfs();
        if (visited1[n] == 0) {
            cout << -1 << endl;
            return 0;
        }
        train = level1[n];
    }
    
    cout << max(train, bus) << endl;

    return 0;
}
