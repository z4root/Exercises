#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  int t, a, b, c;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    if (a == b || b == c) {
      cout << "NO" << endl;
    } else if (a < b && (c - a) == 2) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
