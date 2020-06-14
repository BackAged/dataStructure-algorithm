
#include <bits/stdc++.h>
using namespace std;

string source, destination;
int dx, dy, dz, sx, sy, sz;

int visited[100][100][100];
int forbidden[100][100][100];
int dist[100][100][100];


struct word
{
	int x;
	int y;
	int z;

	word(){};
	word(int x, int y, int z){
	    this->x = x; this->y = y; this->z = z;
	}
};

int bfs(int sx, int sy, int sz) {
    queue<word>q;

    q.push(word(sx, sy, sz));
    dist[sx][sy][sz] = 0;

    while (!q.empty()) {
        word w = q.front();
        q.pop();

        if (w.x == dx && w.y == dy && w.z == dz) {
            return dist[dx][dy][dz];
        }

        // range is 0 - 25
        // for 0  we get => 0 + 1 => 1 && 0 - 1 = -1
        // so we can do 0 + 1 + 26 % 26 => 1 => b && -1 + 26 % 26 = 25 => z


        visited[w.x][w.y][w.z] = 1;

        int f1 = (w.x + 1 + 26) % 26;
        int f2 = (w.x - 1 + 26) % 26;

        int f3 = (w.y + 1 + 26) % 26;
        int f4 = (w.y - 1 + 26) % 26;


        int f5 = (w.z + 1 + 26) % 26;
        int f6 = (w.z - 1 + 26) % 26;


        if (!forbidden[f1][w.y][w.z] && !visited[f1][w.y][w.z]) {
            q.push(word(f1, w.y, w.z));
            dist[f1][w.y][w.z] = dist[w.x][w.y][w.z] + 1;
            visited[f1][w.y][w.z] = 1;
        }

        if (!forbidden[f2][w.y][w.z] && !visited[f2][w.y][w.z]) {
            q.push(word(f2, w.y, w.z));
            dist[f2][w.y][w.z] = dist[w.x][w.y][w.z] + 1;
            visited[f2][w.y][w.z] = 1;
        }

        if (!forbidden[w.x][f3][w.z] && !visited[w.x][f3][w.z]) {
            q.push(word(w.x, f3, w.z));
            dist[w.x][f3][w.z] = dist[w.x][w.y][w.z] + 1;
        }

        if (!forbidden[w.x][f4][w.z] && !visited[w.x][f4][w.z]) {
            q.push(word(w.x,f4, w.z));
            dist[w.x][f4][w.z] = dist[w.x][w.y][w.z] + 1;
            visited[w.x][f4][w.z] = 1;
        }

        if (!forbidden[w.x][w.y][f5] && !visited[w.x][w.y][f5]) {
            q.push(word(w.x, w.y, f5));
            dist[w.x][w.y][f5] = dist[w.x][w.y][w.z] + 1;
            visited[w.x][w.y][f5] = 1;
        }

        if (!forbidden[w.x][w.y][f6] && !visited[w.x][w.y][f6]) {
            q.push(word(w.x, w.y, f6));
            dist[w.x][w.y][f6] = dist[w.x][w.y][w.z] + 1;
            visited[w.x][w.y][f6] = 1;
        }


    }
    return -1;
}



int main()
{
    int t;
    cin >> t;

    for (int cs = 1; cs <= t; cs++) {

        memset(visited, 0, sizeof visited);
        memset(forbidden, 0, sizeof forbidden);
        memset(dist, 0, sizeof dist);


        cin >> source;
        cin >> destination;

        int fn;
        cin >> fn;

        string a, b, c;
        for (int i = 0; i < fn; i++) {
            cin >> a >> b >> c;

            // precomputing forbidden rather than checking every time in bfs
            for (int x = 0; x < a.size(); x++) {
                for (int y = 0; y < b.size(); y++) {
                    for (int z = 0; z < c.size(); z++) {
                        forbidden[a[x]-97][b[y] - 97][c[z]-97] = 1;
                    }
                }
            }

        }

        sx = source[0] - 97;
        sy = source[1] - 97;
        sz = source[2] - 97;


        dx = destination[0] - 97;
        dy = destination[1] - 97;
        dz = destination[2] - 97;

        if (forbidden[dx][dy][dz] || forbidden[sx][sy][sz]) {
            printf("Case %d: %d\n", cs, -1);
            continue;
        }

        int ans = bfs(sx, sy, sz);

        printf("Case %d: %d\n", cs, ans);


    }
    return 0;
}
