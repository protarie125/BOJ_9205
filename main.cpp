#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using Pos = pair<ll, ll>;
using vb = vector<bool>;

ll t, n;
vl X, Y;
ll bx, by, ex, ey;
vb visit;
bool bfs() {
  queue<Pos> q{};
  q.push({bx, by});

  while (!q.empty()) {
    auto [fx, fy] = q.front();
    q.pop();

    const auto& to_end = abs(fx - ex) + abs(fy - ey);
    if (to_end <= 1000) {
      return true;
    }

    for (auto i = 0; i < n; ++i) {
      if (visit[i]) continue;

      const auto& dist = abs(fx - X[i]) + abs(fy - Y[i]);
      if (dist <= 1000) {
        q.push({X[i], Y[i]});
        visit[i] = true;
      }
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> t;
  while (0 < (t--)) {
    cin >> n;
    X = vl(n);
    Y = vl(n);

    cin >> bx >> by;
    for (auto i = 0; i < n; ++i) {
      cin >> X[i] >> Y[i];
    }
    cin >> ex >> ey;

    visit = vb(n, false);
    const auto& ans = bfs();

    if (ans) {
      cout << "happy\n";
    } else {
      cout << "sad\n";
    }
  }

  return 0;
}