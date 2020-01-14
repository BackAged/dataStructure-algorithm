#include <iostream>
#include <vector>
#include<algorithm> 

using namespace std;
int visited[100][100][100];

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c, int as, int bs, int cs) {
    if (as < 0 || bs < 0 || cs < 0) {
      return 0;
    }
    if (visited[as][bs][cs] != -1) {
      return visited[as][bs][cs];
    }

    int ans = 0;
    if (a[as] == b[bs] && b[bs] == c[cs]) {
      ans = max(ans, 1 + lcs3(a, b, c, as-1, bs-1, cs-1));
    } else {
      int t1 = lcs3(a, b, c, as-1, bs, cs);
      int t2 = lcs3(a, b, c, as, bs-1, cs);
      int t3 = lcs3(a, b, c, as, bs, cs-1);
      int t4 = lcs3(a, b, c, as-1, bs, cs-1);
      int t5 = lcs3(a, b, c, as-1, bs-1, cs);
      int t6 = lcs3(a, b, c, as, bs-1, cs-1);
      ans = max({t1, t2, t3, t4, t5, t6});
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
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  fill_3darray(100);
  std::cout << lcs3(a, b, c , a.size()-1, b.size()-1, c.size()-1) << std::endl;
}