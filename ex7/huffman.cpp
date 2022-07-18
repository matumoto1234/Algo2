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


namespace graph_library {
  using namespace std;
}

#include <cassert>
#include <iostream>
#include <type_traits>
#include <vector>

namespace graph_library {
  template <class T>
  class EdgeInterface {
    // TODO: Do implement constructor
    // UnWeightedEdge(from, to)
    // WeightedEdge  (from, to, cost)
  public:
    int &from() {
      return static_cast<T &>(this)->from();
    }

    const int &from() const {
      return static_cast<T &>(this)->from();
    }

    int &to() {
      return static_cast<T &>(this)->to();
    }

    const int &to() const {
      return static_cast<T &>(this)->to();
    }
  };

  template <typename Cost>
  class WeightedEdge: public EdgeInterface<WeightedEdge<Cost>> {
  private:
    int from_, to_;
    Cost cost_;

  public:
    WeightedEdge() = default;
    WeightedEdge(int to): to_(to) {}
    WeightedEdge(int to, Cost cost): to_(to), cost_(cost) {}
    WeightedEdge(int from, int to, Cost cost): from_(from), to_(to), cost_(cost) {}

    bool operator<(const WeightedEdge<Cost> &rhs) const {
      if (cost_ != rhs.cost_)
        return cost_ < rhs.cost_;

      if (from_ != rhs.from_)
        return from_ < rhs.from_;

      return to_ < rhs.to_;
    }

    bool operator<=(const WeightedEdge<Cost> &rhs) const {
      if (cost_ != rhs.cost_)
        return cost_ <= rhs.cost_;

      if (from_ != rhs.from_)
        return from_ <= rhs.from_;

      return to_ <= rhs.to_;
    }

    bool operator>(const WeightedEdge<Cost> &rhs) const {
      if (cost_ != rhs.cost_)
        return cost_ > rhs.cost_;

      if (from_ != rhs.from_)
        return from_ > rhs.from_;

      return to_ > rhs.to_;
    }

    bool operator>=(const WeightedEdge<Cost> &rhs) const {
      if (cost_ != rhs.cost_)
        return cost_ >= rhs.cost_;

      if (from_ != rhs.from_)
        return from_ >= rhs.from_;

      return to_ >= rhs.to_;
    }

    bool operator!=(const WeightedEdge<Cost> &rhs) const {
      return from_ != rhs.from_ or to_ != rhs.to_ or cost_ != rhs.cost_;
    }

    int &from() {
      return from_;
    }

    const int &from() const {
      return from_;
    }

    int &to() {
      return to_;
    }

    const int &to() const {
      return to_;
    }

    Cost &cost() {
      return cost_;
    }

    const Cost &cost() const {
      return cost_;
    }

    template <typename T>
    friend ostream &operator<<(ostream &os, const WeightedEdge<T> &rhs) {
      os << rhs.from_ << ' ' << rhs.to_ << ' ' << rhs.cost_;
      return os;
    }
  };

  class UnWeightedEdge: public EdgeInterface<UnWeightedEdge> {
  private:
    int from_, to_;

  public:
    UnWeightedEdge() = default;
    UnWeightedEdge(int to_): to_(to_) {}
    UnWeightedEdge(int from_, int to_): from_(from_), to_(to_) {}

    bool operator<(const UnWeightedEdge &rhs) const {
      if (from_ != rhs.from_)
        return from_ < rhs.from_;

      return to_ < rhs.to_;
    }

    bool operator<=(const UnWeightedEdge &rhs) const {
      if (from_ != rhs.from_)
        return from_ <= rhs.from_;

      return to_ <= rhs.to_;
    }

    bool operator>(const UnWeightedEdge &rhs) const {
      if (from_ != rhs.from_)
        return from_ > rhs.from_;

      return to_ > rhs.to_;
    }

    bool operator>=(const UnWeightedEdge &rhs) const {
      if (from_ != rhs.from_)
        return from_ >= rhs.from_;

      return to_ >= rhs.to_;
    }

    bool operator!=(const UnWeightedEdge &rhs) const {
      return from_ != rhs.from_ or to_ != rhs.to_;
    }

    int &from() {
      return from_;
    }

    const int &from() const {
      return from_;
    }

    int &to() {
      return to_;
    }

    const int &to() const {
      return to_;
    }

    friend ostream &operator<<(ostream &os, const UnWeightedEdge &rhs) {
      os << rhs.from_ << ' ' << rhs.to_;
      return os;
    }
  };

  template <typename Cost>
  using WeightedEdges = vector<WeightedEdge<Cost>>;

  using UnWeightedEdges = vector<UnWeightedEdge>;


  template <class Edge, bool is_extended_edge = is_base_of_v<EdgeInterface<Edge>, Edge>>
  class Graph {
    static_assert(is_extended_edge, "Edge is not extended edge interface class.");
  };

  template <class Edge>
  class Graph<Edge, true> {
  public:
    using Edges = vector<Edge>;

  private:
    Edges edges_;
    vector<Edges> graph_;
    int size_;

  public:
    Graph() = default;
    Graph(int N): graph_(N), size_(N) {}

    int size() const {
      return size_;
    }

    void add_edge(const Edge &edge) {
      const int &from = edge.from();
      graph_.at(from).push_back(edge);
      edges_.push_back(edge);
    }

    Edge get_edge(int k) const {
      return edges_.at(k);
    }

    Edges edges() const {
      return edges_;
    }

    void pop_back_edge() {
      assert(not edges_.empty());

      const Edge e = edges_.back();
      edges_.pop_back();
      graph_.at(e.from()).pop_back();
    }

    vector<Edges> graph() const {
      return graph_;
    }
  };

  template <typename Cost>
  using WeightedGraph = Graph<WeightedEdge<Cost>>;

  using UnWeightedGraph = Graph<UnWeightedEdge>;
} // namespace graph_library

namespace string_library {
  using namespace std;
}

#include <algorithm>
#include <cstdint>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>

namespace string_library {
  class HuffmanEdge: public graph_library::EdgeInterface<HuffmanEdge> {
    int from_, to_, bit_;

  public:
    HuffmanEdge() = default;
    HuffmanEdge(int to): to_(to) {}
    HuffmanEdge(int from, int to): from_(from), to_(to) {}
    HuffmanEdge(int from, int to, int bit): from_(from), to_(to), bit_(bit) {}

    int &from() {
      return from_;
    }

    const int &from() const {
      return from_;
    }

    int &to() {
      return to_;
    }

    const int &to() const {
      return to_;
    }

    int &bit() {
      return bit_;
    }

    const int &bit() const {
      return bit_;
    }

    friend ostream &operator<<(ostream &os, const HuffmanEdge &rhs) {
      os << "from:" << rhs.from_ << " to:" << rhs.to_ << " bit:" << rhs.bit_;
      return os;
    }
  };


  class HuffmanCoding {
    graph_library::Graph<HuffmanEdge> binary_tree_;
    unordered_map<int, vector<bool>> huffman_code_;
    unordered_map<char, int> ch_to_idx_, frequency_;
    unordered_map<int, char> idx_to_ch_;
    string unique_s_;

    void dfs(const vector<vector<HuffmanEdge>> &adj_list, int v, int pre) {
      for (const auto &e: adj_list[v]) {
        const int &to = e.to();
        if (to == pre)
          continue;

        huffman_code_[to] = huffman_code_[v];
        huffman_code_[to].push_back(bool(e.bit()));

        dfs(adj_list, to, v);
      }
    }

  public:
    HuffmanCoding(const string &s) {
      for (const char &ch: s) {
        frequency_[ch]++;
      }

      unique_s_ = s;
      sort(unique_s_.begin(), unique_s_.end());
      unique_s_.erase(unique(unique_s_.begin(), unique_s_.end()), unique_s_.end());

      for (int i = 0; i < int(unique_s_.size()); i++) {
        const char &ch = unique_s_[i];
        ch_to_idx_[ch] = i;
        idx_to_ch_[i] = ch;
      }

      // count, index
      using pic = pair<int, int>;
      priority_queue<pic, vector<pic>, greater<pic>> pq;

      for (const auto &[ch, cnt]: frequency_) {
        pq.emplace(cnt, ch_to_idx_.at(ch));
      }

      int idx = unique_s_.size();
      const int nodes_count = idx + idx + 1;

      if (int(pq.size()) == 1) {
        pq.emplace(/*count=*/0, nodes_count /*to 0-indexed*/ - 1);
      }

      binary_tree_ = graph_library::Graph<HuffmanEdge>(nodes_count);

      constexpr int LEFT_BIT = 0;
      constexpr int RIGHT_BIT = 1;

      while (int(pq.size()) >= 2) {
        const auto [cnt_left, idx_left] = pq.top();
        pq.pop();

        const auto [cnt_right, idx_right] = pq.top();
        pq.pop();

        binary_tree_.add_edge(HuffmanEdge(idx_left, idx, LEFT_BIT));
        binary_tree_.add_edge(HuffmanEdge(idx, idx_left, LEFT_BIT));

        binary_tree_.add_edge(HuffmanEdge(idx_right, idx, RIGHT_BIT));
        binary_tree_.add_edge(HuffmanEdge(idx, idx_right, RIGHT_BIT));
        pq.emplace(cnt_left + cnt_right, idx);
        idx++;
      }

      dfs(binary_tree_.graph(), /*root=*/idx - 1, /*not exist node=*/-1);
    }

    graph_library::Graph<HuffmanEdge> binary_tree() const {
      return binary_tree_;
    }

    char index_to_char(int idx) const {
      return idx_to_ch_.at(idx);
    }

    int char_to_index(char ch) const {
      return ch_to_idx_.at(ch);
    }

    string unique_string() const {
      return unique_s_;
    }

    vector<bool> code(char ch) const {
      int idx = ch_to_idx_.at(ch);
      return huffman_code_.at(idx);
    }

    unordered_map<char, int> frequency() const {
      return frequency_;
    }
  };
} // namespace string_library


using namespace string_library;

int main() {
  string s;
  cin >> s;

  HuffmanCoding hc(s);

  string unique_s = hc.unique_string();
  for (const char &c: unique_s) {
    vector<bool> bits = hc.code(c);

    cout << "char:" << c << " bit:";
    for (const bool &bit: bits) {
      cout << bit;
    }
    cout << newl;
  }
}
