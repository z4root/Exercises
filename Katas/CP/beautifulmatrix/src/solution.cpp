#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  int m[5][5];
  int p;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> m[i][j];

      if (m[i][j] == 1) {
        int steps = abs(2 - i) + abs(2 - j);
        cout << steps << endl;
      }
    }
  }
}
