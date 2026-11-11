#include <bits/stdc++.h>
#include <map>
using namespace std;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  string u;
  cin >> u;

  map<char, int> w;
  int t = 0;
  for (int i = 0; i < u.length(); i++) {
    auto it = w.find(u[i]);
    if (it == w.end()) {
      w.insert({u[i], 1});
      t++;
    }
  }

  (t % 2 == 0 ? cout << "CHAT WITH HER!" << endl
              : cout << "IGNORE HIM!" << endl);
  return 0;
}
