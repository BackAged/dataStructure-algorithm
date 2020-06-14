#include <bits/stdc++.h>
using namespace std;

/*
    => star graph
*/
map<int, int> cant;

int main()
{
    int n, m, u, v;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        cant[u] = 1;
        cant[v] = 1;
    }
    int star_center;
    for (int i = 1; i <= n; i++) {
        if (cant[i] == 0) {
            star_center = i;
            break;
        }
    }
    cout << n -1 << endl;
    for (int i = 1; i <= n; i++) {
        if (star_center == i)
            continue;
        cout << i << " " << star_center << endl;
    }
}
