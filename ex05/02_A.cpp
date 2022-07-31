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
    WeightedEdge(int to_): to_(to_) {}
    WeightedEdge(int to_, Cost cost_): to_(to_), cost_(cost_) {}
    WeightedEdge(int from_, int to_, Cost cost_): from_(from_), to_(to_), cost_(cost_) {}

    bool operator<(const WeightedEdge<Cost> &rhs) const {
      return cost_ < rhs.cost_;
    }

    bool operator<=(const WeightedEdge<Cost> &rhs) const {
      return cost_ <= rhs.cost_;
    }

    bool operator>(const WeightedEdge<Cost> &rhs) const {
      return cost_ > rhs.cost_;
    }

    bool operator>=(const WeightedEdge<Cost> &rhs) const {
      return cost_ >= rhs.cost_;
    }

    bool operator!=(const WeightedEdge<Cost> &rhs) const {
      return from_ != rhs.from_ and to_ != rhs.to_ and cost_ != rhs.cost_;
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
  };

  class UnWeightedEdge: public EdgeInterface<UnWeightedEdge> {
  private:
    int from_, to_;

  public:
    UnWeightedEdge() = default;
    UnWeightedEdge(int to_): to_(to_) {}
    UnWeightedEdge(int from_, int to_): from_(from_), to_(to_) {}

    bool operator!=(const UnWeightedEdge &rhs) const {
      return from_ != rhs.from_ and to_ != rhs.to_;
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


namespace data_structure_library {
  using namespace std;
}

#include <numeric>
#include <vector>

namespace data_structure_library {
  class UnionFind {
    // number of vertices
    int n_;

    vector<int> sizes_, parents_;

  public:
    UnionFind(int n): n_(n), sizes_(n, 1), parents_(n) {
      iota(parents_.begin(), parents_.end(), 0);
    }

    // 根（そのグループの識別番号）
    int root(int x) {
      if (x == parents_[x])
        return x;
      return parents_[x] = root(parents_[x]);
    }

    int size(int x) {
      return sizes_[root(x)];
    }

    bool same(int x, int y) {
      return root(x) == root(y);
    }

    // size(x) < size(y): -1
    // not merged:         0
    // size(x) > size(y): +1
    int merge(int x, int y) {
      x = root(x);
      y = root(y);
      if (x == y)
        return 0;

      int result = +1;
      if (sizes_[x] < sizes_[y]) {
        swap(x, y);
        result = -1;
      }

      sizes_[x] += sizes_[y];
      parents_[y] = x;

      return result;
    }

    vector<vector<int>> groups() {
      vector<vector<int>> grps(n_);
      for (int i = 0; i < n_; i++) {
        grps[root(i)].emplace_back(i);
      }
      vector<vector<int>> res;
      for (int i = 0; i < n_; i++) {
        if (grps[i].empty())
          continue;
        res.emplace_back(grps[i]);
      }
      return res;
    }
  };
} // namespace data_structure_library


namespace graph_library {

  template <typename Cost>
  struct MinimumSpanningTree {
    WeightedGraph<Cost> graph_;
    WeightedGraph<Cost> mst_;
    MinimumSpanningTree(const WeightedGraph<Cost> &graph): graph_(graph) {}

    Cost kruskal() {
      mst_ = WeightedGraph<Cost>(graph_.size()); // init
      if (graph_.size() == 0) {
        return Cost(0);
      }

      vector<WeightedEdge<Cost>> edges = graph_.edges();
      sort(edges.begin(), edges.end());

      data_structure_library::UnionFind uf(graph_.size());

      Cost sum = 0;

      for (auto edge: edges) {
        int from = edge.from();
        int to = edge.to();

        if (uf.same(from, to))
          continue;

        uf.merge(from, to);
        sum += edge.cost();
        mst_.add_edge(edge);
      }

      return sum;
    }

    Cost prim() {
      mst_ = WeightedGraph<Cost>(graph_.size()); // init
      if (graph_.size() == 0) {
        return Cost(0);
      }

      priority_queue<WeightedEdge<Cost>, vector<WeightedEdge<Cost>>, greater<WeightedEdge<Cost>>> pq;
      pq.emplace(/*from=*/0, /*to=*/0, Cost(0));

      vector<vector<WeightedEdge<Cost>>> adj_list = graph_.graph();
      vector<bool> used(graph_.size(), false);

      Cost sum = 0;

      while (not pq.empty()) {
        auto e = pq.top();
        pq.pop();

        int v = e.to();

        if (used[v])
          continue;

        sum += e.cost();
        used[v] = true;
        mst_.add_edge(e);

        for (auto edge: adj_list[v]) {
          int to = edge.to();

          if (used[to])
            continue;

          pq.push(edge);
        }
      }

      return sum;
    }
  };

} // namespace graph_library

using namespace graph_library;

int main() {
  int v, e;
  cin >> v >> e;

  WeightedGraph<ll> g(v);
  rep(i, e) {
    int s, t, w;
    cin >> s >> t >> w;

    g.add_edge(WeightedEdge<ll>(s, t, w));
    g.add_edge(WeightedEdge<ll>(t, s, w));
  }
  MinimumSpanningTree<ll> mst(g);
  ll ans = mst.prim();
  cout << ans << endl;
}
