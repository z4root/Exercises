#include <bits/stdc++.h>
#include <map>
#include <string>
using namespace std;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  string w1, w2;
  cin >> w1 >> w2;
  int len = w1.length();
  std::transform(w1.begin(), w1.end(), w1.begin(), ::tolower);
  std::transform(w2.begin(), w2.end(), w2.begin(), ::tolower);
  for (int i = 0; i < len; i++) {
    if (w1[i] > w2[i]) {
      cout << 1;
      break;
    } else if (w1[i] < w2[i]) {
      cout << -1;
      break;
    } else if (w1[i] == w2[i] && i == len - 1) {
      cout << 0;
      break;
    }
  }
  return 0;
}

// int v1, v2;
// v1 = 0;
// v2 = 0;
// map<char, int> values = {
//     {'a', 0},  {'b', 1},  {'c', 2},  {'d', 3},  {'e', 4},  {'f', 5},
//     {'g', 6},  {'h', 7},  {'i', 8},  {'j', 9},  {'k', 10}, {'l', 11},
//     {'m', 12}, {'n', 13}, {'o', 14}, {'p', 15}, {'q', 16}, {'r', 17},
//     {'s', 18}, {'t', 19}, {'u', 20}, {'v', 21}, {'w', 22}, {'x', 23},
//     {'y', 24}, {'z', 25}
//
// };

//   for (int i = 0; i < w1.length(); i++) {
//     v1 += values.at(w1[i]);
//     v2 += values.at(w2[i]);
//   }
//   if (v1 > v2) {
//     cout << 1 << endl;
//   } else if (v1 < v2) {
//     cout << -1 << endl;
//   } else {
//     cout << 0 << endl;
//   }
//
//   return 0;
// }
