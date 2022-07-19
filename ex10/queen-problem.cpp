#include <bits/stdc++.h>
using namespace std;

// {{{ Templates

// clang-format off

// Macros
#define over_load_(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) over_load_(__VA_ARGS__, rep4, rep3, rep2)(__VA_ARGS__)
#define rep2(i, r) for ( int i = 0; i < static_cast<int>(r); (i) += 1)
#define rep3(i, l, r) for ( int i = static_cast<int>(l); i < static_cast<int>(r); (i) += 1)
#define rep4(i, l, r, stride) for ( int i = static_cast<int>(l); i < static_cast<int>(r); (i) += (stride))
#define rrep(...) over_load_(__VA_ARGS__, rrep4, rrep3, rrep2)(__VA_ARGS__)
#define rrep2(i, r) for ( int i = static_cast<int>(r) - 1; i >= 0; (i) -= 1)
#define rrep3(i, l, r) for ( int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= 1)
#define rrep4(i, l, r, stride) for ( int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= (stride))
#define len(x) (static_cast<int>((x).size()))
#define whole(f, x, ...) ([&](decltype((x)) container) { return (f)( begin(container), end(container), ## __VA_ARGS__); })(x)
#define rwhole(f, x, ...) ([&](decltype((x)) container) { return (f)( rbegin(container), rend(container), ## __VA_ARGS__); })(x)
#define debug(...) debug_function(#__VA_ARGS__, __VA_ARGS__)

// Operators
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &v) { bool is_first = true; for (auto x: v) { os << (is_first ? "" : " ") << x; is_first = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, queue<T> v) { bool is_first = true; while (!v.empty()) { os << (is_first?"":" ")<<v.front(); v.pop(); is_first = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, stack<T> v) { bool is_first = true; while (!v.empty()) { os << (is_first?"":" ") << v.top(); v.pop(); is_first=false; } return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { rep (i, len(v)) os << v[i] << (i == len(v) - 1 ? "" : " "); return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<vector<T>> &v) { for (const auto &vec: v) { os << vec << '\n'; } return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &v) { rep (i, len(v)) os << v[i] << (i == len(v) - 1 ? "" : " "); return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) { bool is_first = true; for (T x: v) { os << (is_first ? "" : " ") << x; is_first = false; } return os; }
template <typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &in: v) { is >> in; } return is; }

// For debug macro
int find_comma_not_bracketed(string_view s){ stack<char> bs; string lbs = "({[", rbs = ")}]"; for (size_t i = 0; i < s.size(); i++) { if (lbs.find(s[i]) != string::npos) bs.push(s[i]); if (rbs.find(s[i]) != string::npos and !bs.empty()) bs.pop(); if (s[i] == ',' and bs.empty()) return i; } return s.size(); }
template <typename T, typename... Ts> void debug_function(string_view name, const T &a, Ts &&...rest) { int end = find_comma_not_bracketed(name); cerr << name.substr(0, end) << ":" << a; if constexpr (sizeof...(rest) == 0) { cerr << '\n'; } else { cerr << ' '; debug_function(name.substr(name.find_first_not_of(' ', end + 1)), forward<Ts>(rest)...); } }

// Functions
template <typename T> vector<T> make_vector(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_vector(size_t a, Ts... ts) { return vector<decltype(make_vector(ts...))>(a, make_vector(ts...)); }
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b and (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b and (a = b, true); }

// Structs
struct IoSetup { IoSetup(int x = 15) { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(x); cerr << fixed << setprecision(x); } } iosetup;

// Type aliases
using ull = unsigned long long;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

// Literals
constexpr ll INF64 = INT64_MAX / 2;
constexpr int INF32 = INT32_MAX / 2;
constexpr int dy[] = { 0, 1, -1, 0, -1, 1, -1, 1 };
constexpr int dx[] = { 1, 0, 0, -1, -1, -1, 1, 1 };
constexpr int mod998244353 = 998244353;
constexpr int mod1000000007 = static_cast<int>(1e9) + 7;
constexpr char newl = '\n';

// clang-format on

// }}} Templates


class QueenProblemSolver {
  int n_;
  vector<vector<int>> queens_;
  vector<int> vertical_used_, horizontal_used_, upward_used_, downward_used_;
  set<vector<vector<int>>> answers_;

  int vertical_idx([[maybe_unused]] int y, int x) const {
    return x;
  }

  int horizontal_idx(int y, [[maybe_unused]] int x) const {
    return y;
  }

  int upward_idx(int y, int x) const {
    return y + x;
  }

  int downward_idx(int y, int x) const {
    // I want to (y - x) as index, but that appears minus number.
    // So, plus (0-indexed n).
    return y - x + (n_ - 1);
  }

  bool is_safe(int y, int x) const {
    int v_idx = vertical_idx(y, x);
    int h_idx = horizontal_idx(y, x);
    int u_idx = upward_idx(y, x);
    int d_idx = downward_idx(y, x);

    return not(vertical_used_[v_idx] or horizontal_used_[h_idx] or upward_used_[u_idx] or downward_used_[d_idx]);
  }

  void found_answer() {
    answers_.insert(queens_);
  }

  void dfs(int y, int x, int depth) {
    if (depth == n_) {
      if (answers_.find(queens_) == answers_.end()) {
        found_answer();
      }
      return;
    }

    if (not is_safe(y, x)) {
      return;
    }

    int v_idx = vertical_idx(y, x);
    int h_idx = horizontal_idx(y, x);
    int u_idx = upward_idx(y, x);
    int d_idx = downward_idx(y, x);

    vertical_used_[v_idx] = 1;
    horizontal_used_[h_idx] = 1;
    upward_used_[u_idx] = 1;
    downward_used_[d_idx] = 1;
    queens_[y][x] = 1;

    for (int col = 0; col < n_; col++) {
      dfs(y + 1, col, depth + 1);
    }

    vertical_used_[v_idx] = 0;
    horizontal_used_[h_idx] = 0;
    upward_used_[u_idx] = 0;
    downward_used_[d_idx] = 0;
    queens_[y][x] = 0;
    queens_[y][x] = 0;
  }

public:
  QueenProblemSolver(int n): n_(n), queens_(n, vector<int>(n, 0)), vertical_used_(n, 0), horizontal_used_(n, 0), upward_used_(2 * n - 1, 0), downward_used_(2 * n - 1, 0) {
    for (int col = 0; col < n; col++) {
      dfs(0, col, 0);
    }
  }

  set<vector<vector<int>>> answers() const {
    return answers_;
  }
};


int main() {
  QueenProblemSolver solver(8);
  auto answers = solver.answers();

  cout << "number of answers:" << answers.size() << endl;

  int count = 1;
  for (auto answer: answers) {
    cout << "-------------------------" << count << endl;
    cout << answer;
    cout << "-------------------------" << endl;
    count++;
  }
}
