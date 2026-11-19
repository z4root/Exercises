#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  int t, n;
  string s;
  cin >> t;

  while (t--) {
    cin >> n;
    cin >> s;
    int m = 0;
    for (int i = 0; i < n; i++) {
      if ((i == 0 && s[i] == 'B') || (i != 0 && s[i] == s[i - 1])) {
        m++;
      }
    }
    cout << m << endl;
  }

  // Patron es R-B-R-B-R-B
  // Si tengo R su anterior es B y su siguente B
  // Si tengo B su anterior es  R y su siguietne R
}
