#include <iostream>

#include <vector>

#include<algorithm>

using namespace std;
int visited[101][101][101];

int lcs3iterative(vector < int > &a, vector < int > &b, vector < int > &c) {
    int as = a.size(), bs = a.size(), cs = c.size();

    for (int i = 0; i <= as; i++) {
        for (int j = 0; j <= bs; j++) {
            for (int k = 0; k <= cs; k++) {
                if (i == 0 || j == 0 || k == 0) {
                    visited[i][j][k] = 0;
                } else if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) {
                    visited[i][j][k] = max(visited[i][j][k], visited[i - 1][j - 1][k - 1] + 1);
                } else {
                  visited[i][j][k] = max({
                        visited[i][j][k],
                        visited[i - 1][j][k],
                        visited[i][j - 1][k],
                        visited[i][j][k - 1],
                        visited[i - 1][j - 1][k],
                        visited[i - 1][j][k - 1],
                        visited[i][j - 1][k - 1],
                        visited[i - 1][j - 1][k - 1],
                  });
                }
            }
        }
    }

    return visited[as][bs][cs];
}

int lcs3Recursive(vector < int > & a, vector < int > & b, vector < int > & c, int as, int bs, int cs) {
    if (as < 0 || bs < 0 || cs < 0) {
        return 0;
    }
    if (visited[as][bs][cs] != -1) {
        return visited[as][bs][cs];
    }

    int ans = 0;
    if (a[as] == b[bs] && b[bs] == c[cs]) {
        ans = max(ans, 1 + lcs3Recursive(a, b, c, as - 1, bs - 1, cs - 1));
    } else {
        int t1 = lcs3Recursive(a, b, c, as - 1, bs, cs);
        int t2 = lcs3Recursive(a, b, c, as, bs - 1, cs);
        int t3 = lcs3Recursive(a, b, c, as, bs, cs - 1);
        int t4 = lcs3Recursive(a, b, c, as - 1, bs, cs - 1);
        int t5 = lcs3Recursive(a, b, c, as - 1, bs - 1, cs);
        int t6 = lcs3Recursive(a, b, c, as, bs - 1, cs - 1);
        ans = max({t1,t2,t3,t4,t5,t6});
    }

    visited[as][bs][cs] = ans;
    return ans;
}

void fill_3darray(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                visited[i][j][k] = -1;
            }
        }
    }
}


int main() {
    size_t an;
    std::cin >> an;
    vector < int > a(an);
    for (size_t i = 0; i < an; i++) {
        std::cin >> a[i];
    }
    size_t bn;
    std::cin >> bn;
    vector < int > b(bn);
    for (size_t i = 0; i < bn; i++) {
        std::cin >> b[i];
    }
    size_t cn;
    std::cin >> cn;
    vector < int > c(cn);
    for (size_t i = 0; i < cn; i++) {
        std::cin >> c[i];
    }
    fill_3darray(101);
    //std::cout << lcs3Recursive(a, b, c , a.size()-1, b.size()-1, c.size()-1) << std::endl;
    std::cout << lcs3iterative(a, b, c) << std::endl;
    print_visited(a.size(), b.size(), c.size());
}