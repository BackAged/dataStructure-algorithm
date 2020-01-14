#include <iostream>
#include <algorithm>
using namespace std;

int visited[1004];
int get_change(int m) {
    if (m == 0) {
      return 0;
    }
    if (visited[m]) {
      return visited[m];
    }

    int takingOne = INT32_MAX, takingThree = INT32_MAX, takingFour = INT32_MAX;
    if (m - 1 >= 0) {
        takingOne = 1 + get_change(m - 1);
    }

    if (m - 3 >= 0) {
        takingThree = 1 + get_change(m - 3);
    }

    if (m - 4 >= 0) {
       takingFour = 1 + get_change(m - 4);
    }

    visited[m] = min(takingOne, min(takingThree, takingFour));
    return visited[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}