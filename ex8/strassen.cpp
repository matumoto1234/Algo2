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



namespace math_library {
  using namespace std;
  using ll = long long;
} // namespace math_library

#include <cassert>
#include <vector>

namespace math_library {
  template <typename T>
  class Matrix {
    int row_, column_;
    vector<vector<T>> matrix_;

  public:
    Matrix() = default;
    Matrix(const vector<vector<T>> &matrix): matrix_(matrix) {
      if (matrix.empty()) {
        row_ = 0;
        column_ = 0;
        return;
      }

      row_ = matrix_.size();
      column_ = matrix.at(0).size();

      for (const vector<T> &line: matrix) {
        int col = line.size();
        assert(col == column_);
      }
    }

    int row() const {
      return row_;
    }

    int column() const {
      return column_;
    }

    constexpr Matrix pow(long long n) const {
      assert(n >= 0);

      Matrix x = /* base = */ *this;
      Matrix res(vector<vector<T>>(row_, vector<T>(column_, /*product identity element=*/T(1))));

      while (n) {
        if (n & 1) {
          res *= x;
        }
        x *= x;
        n >>= 1;
      }
      return res;
    }

    vector<vector<T>> matrix() const {
      return matrix_;
    }

    Matrix<T> operator+=(const Matrix &rhs) {
      assert(row_ == rhs.row_);
      assert(column_ == rhs.column_);

      for (int i = 0; i < row_; i++) {
        for (int j = 0; j < column_; j++) {
          matrix_.at(i).at(j) += rhs.matrix_.at(i).at(j);
        }
      }
      return matrix_;
    }

    Matrix<T> operator-=(const Matrix &rhs) {
      assert(row_ == rhs.row_);
      assert(column_ == rhs.column_);

      for (int i = 0; i < row_; i++) {
        for (int j = 0; j < column_; j++) {
          matrix_.at(i).at(j) -= rhs.matrix_.at(i).at(j);
        }
      }
      return matrix_;
    }

    Matrix<T> operator*=(const Matrix &rhs) {
      assert(column_ == rhs.row_);

      vector<vector<T>> prod(row_, vector<T>(rhs.column_, /*additive identity element=*/T(0)));

      // https://qiita.com/ageprocpp/items/7bda728d109c953ece3c
      for (int i = 0; i < row_; i++) {
        for (int k = 0; k < column_; k++) {
          for (int j = 0; j < rhs.column_; j++) {
            prod.at(i).at(j) += matrix_.at(i).at(k) * rhs.matrix_.at(k).at(j);
          }
        }
      }

      return matrix_ = prod;
    }

    Matrix<T> operator*=(const T &scalar) {
      for (int i = 0; i < row_; i++) {
        for (int j = 0; j < column_; j++) {
          matrix_.at(i).at(j) *= scalar;
        }
      }
      return matrix_;
    }

    Matrix<T> operator+() const {
      return *this;
    }

    Matrix<T> operator-() const {
      return Matrix(this->matrix_) - *this;
    }

    constexpr friend Matrix<T> operator+(const Matrix<T> &lhs, const Matrix<T> &rhs) {
      return Matrix<T>(lhs) += rhs;
    }

    constexpr friend Matrix<T> operator-(const Matrix<T> &lhs, const Matrix<T> &rhs) {
      return Matrix<T>(lhs) -= rhs;
    }

    constexpr friend Matrix<T> operator*(const Matrix<T> &lhs, const Matrix<T> &rhs) {
      return Matrix<T>(lhs) *= rhs;
    }

    constexpr friend bool operator==(const Matrix<T> &lhs, const Matrix<T> &rhs) {
      return lhs.matrix_ == rhs.matrix_;
    }

    constexpr friend bool operator!=(const Matrix<T> &lhs, const Matrix<T> &rhs) {
      return lhs.matrix_ != rhs.matrix_;
    }

    friend ostream &operator<<(ostream &os, const Matrix<T> &rhs) {
      for (int i = 0; i < rhs.row_; i++) {
        for (int j = 0; j < rhs.column_; j++) {
          os << rhs.matrix_.at(i).at(j);
          os << (j == rhs.column_ - 1 ? "\n" : " ");
        }
      }
      return os;
    }
  };
} // namespace math_library


using namespace math_library;


template <typename T>
Matrix<T> subsequence(const Matrix<T> &m, int row_begin, int row_end, int col_begin, int col_end) {
  auto matrix = m.matrix();

  int height = row_end - row_begin;
  int width = col_end - col_begin;
  vector<vector<T>> result(height, vector<T>(width, 0));

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      result[i][j] = matrix.at(row_begin + i).at(col_begin + j);
    }
  }
  return result;
}

template <typename T>
tuple<Matrix<T>, Matrix<T>, Matrix<T>, Matrix<T>> partition_matrix(const Matrix<T> &m) {
  assert(m.row() == m.column());
  assert(m.row() % 2 == 0);

  int n = m.row();

  vector<vector<T>> matrix = m.matrix();

  Matrix<T> m11 = subsequence(m, 0, n / 2, 0, n / 2);
  Matrix<T> m12 = subsequence(m, 0, n / 2, n / 2, n);
  Matrix<T> m21 = subsequence(m, n / 2, n, 0, n / 2);
  Matrix<T> m22 = subsequence(m, n / 2, n, n / 2, n);

  return tuple(m11, m12, m21, m22);
}

template <typename T>
Matrix<T> make_matrix(Matrix<T> m11, Matrix<T> m12, Matrix<T> m21, Matrix<T> m22) {
  int n = m11.row() + m12.row();
  vector<vector<T>> result(n, vector<T>(n, 0));

  auto f = [&](const vector<vector<T>> &matrix, int row_begin, int row_end, int col_begin, int col_end) {
    for (int i = row_begin; i < row_end; i++) {
      for (int j = col_begin; j < col_end; j++) {
        result[i][j] = matrix[i - row_begin][j - col_begin];
      }
    }
  };

  f(m11.matrix(), 0, n / 2, 0, n / 2);
  f(m12.matrix(), 0, n / 2, n / 2, n);
  f(m21.matrix(), n / 2, n, 0, n / 2);
  f(m22.matrix(), n / 2, n, n / 2, n);
  return Matrix<T>(result);
}


template <typename T>
Matrix<T> recursive_mul(const Matrix<T> &a, const Matrix<T> &b) {
  assert(a.row() == a.column());

  int n = a.row();

  if (n == 1) {
    vector<vector<T>> result = { { a.matrix()[0][0] * b.matrix()[0][0] } };
    return Matrix<T>(result);
  }

  auto [a11, a12, a21, a22] = partition_matrix(a);
  auto [b11, b12, b21, b22] = partition_matrix(b);
  auto c11 = recursive_mul(a11, b11) + recursive_mul(a12, b21);
  auto c12 = recursive_mul(a11, b12) + recursive_mul(a12, b22);
  auto c21 = recursive_mul(a21, b11) + recursive_mul(a22, b21);
  auto c22 = recursive_mul(a21, b12) + recursive_mul(a22, b22);
  return make_matrix(c11, c12, c21, c22);
}

template <typename T>
Matrix<T> strassen_mul(const Matrix<T> &a, const Matrix<T> &b) {
  assert(a.row() == a.column());

  int n = a.row();

  if (n == 1) {
    vector<vector<T>> result = { { a.matrix()[0][0] * b.matrix()[0][0] } };
    return Matrix<T>(result);
  }

  auto [a11, a12, a21, a22] = partition_matrix(a);
  auto [b11, b12, b21, b22] = partition_matrix(b);

  auto p1 = strassen_mul(a11 + a22, b11 + b22);
  auto p2 = strassen_mul(a21 + a22, b11);
  auto p3 = strassen_mul(a11, b12 - b22);
  auto p4 = strassen_mul(a22, b21 - b11);
  auto p5 = strassen_mul(a11 + a12, b22);
  auto p6 = strassen_mul(a21 - a11, b11 + b12);
  auto p7 = strassen_mul(a12 - a22, b21 + b22);

  auto c11 = p1 + p4 - p5 + p7;
  auto c12 = p3 + p5;
  auto c21 = p2 + p4;
  auto c22 = p1 + p3 - p2 + p6;
  return make_matrix(c11, c12, c21, c22);
}

namespace tools_library {
  using namespace std;
}

#include <chrono>

namespace tools_library {
  struct Stopwatch {
    chrono::high_resolution_clock::time_point start;

    Stopwatch() {
      restart();
    }

    void restart() {
      start = chrono::high_resolution_clock::now();
    }

    chrono::milliseconds::rep elapsed() {
      auto end = chrono::high_resolution_clock::now();
      return chrono::duration_cast<chrono::milliseconds>(end - start).count();
    }
  };
} // namespace tools_library


struct RandomNumberGenerator {
  mt19937 mt;

  RandomNumberGenerator(): mt(chrono::steady_clock::now().time_since_epoch().count()) {}

  int operator()(int a, int b) { // [a, b)
    uniform_int_distribution<int> dist(a, b - 1);
    return dist(mt);
  }

  int operator()(int b) { // [0, b)
    return (*this)(0, b);
  }
};

using namespace tools_library;

int main() {
  cout << "please input 2^x number. (x >= 0)" << endl;
  int n;
  cin >> n;

  auto a = make_vector(n, n, 0LL);
  auto b = make_vector(n, n, 0LL);

  RandomNumberGenerator rand;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = rand(/*upper = */ 1 << 16);
      b[i][j] = rand(/*upper = */ 1 << 16);
    }
  }

  Stopwatch stopwatch;
  auto result_recursive = recursive_mul(Matrix<ll>(a), Matrix<ll>(b)).matrix();
  cout << "[INFO] recursive multiply time: " << stopwatch.elapsed() << "[ms]" << newl;

  stopwatch.restart();
  auto result_strassen = recursive_mul(Matrix<ll>(a), Matrix<ll>(b)).matrix();
  cout << "[INFO] strassen multiply time: " << stopwatch.elapsed() << "[ms]" << newl;

  if (result_recursive == result_strassen) {
    cout << "[INFO] verify the results are same." << newl;
  } else {
    cout << "[ERROR] the results are different." << newl;
  }
}
