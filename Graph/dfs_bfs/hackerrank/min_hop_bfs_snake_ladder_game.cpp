#include <bits/stdc++.h>

using namespace std;
int ladders[105];
int snakes[105];
int dist[105];


// i ran diskarta and got wrong coulnt figure it out why
// but bfs is efficient here, as the cost going from one node n to n+1, n+2, n+3, n+4, n+5, n+6 is one


void bfs() {
    queue<int>q;
    q.push(1);
    dist[1] = 0;
    
    q.push(1);
    
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        
        for (int i = 1; i <= 6; i++) {
            int to = f + i;
            
            if (to > 100)
                continue;
                
            if (ladders[to] != 0) // must go up through the ladder problem says
                to = ladders[to];
                
            if (snakes[to] != 0) // must go down the snakes problem says
                to = snakes[to];
                
            
            if (dist[to] == -1) {
                q.push(to);
                dist[to] = dist[f] + 1;
            } 
        }
    }
    
}


int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        
        memset(snakes, 0, sizeof snakes);
        memset(ladders, 0, sizeof ladders);
        memset(dist, -1, sizeof dist);
        
        int n;
        cin >> n;
        
        // ladders start to end edges
        int a, b;
        for(int ladders_i = 0;ladders_i < n;ladders_i++){
            cin >> a >> b;
            ladders[a] = b;
        }
        
        int m;
        cin >> m;
        
        //snakes start to end edges
        for(int snakes_i = 0;snakes_i < m;snakes_i++){
            cin >> a >> b;
            snakes[a] = b;
        }
        
        bfs();
        
        cout << dist[100] << endl;
     
    }
    return 0;
}
