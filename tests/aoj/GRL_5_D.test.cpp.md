---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/binary-indexed-tree.hpp
    title: BinaryIndexedTree
  - icon: ':heavy_check_mark:'
    path: graph/euler-tour.hpp
    title: graph/euler-tour.hpp
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: Graph Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_D
  bundledCode: "#line 1 \"tests/aoj/GRL_5_D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_D\"\
    \n#include <bits/stdc++.h>\n#line 3 \"graph/graph-template.hpp\"\n/**\n * @brief\
    \ Graph Template\n */\ntemplate<typename T = int>\nstruct Edge {\n    int from,\
    \ to;\n    T cost;\n    int idx;\n    Edge() = default;\n    Edge(int from, int\
    \ to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}\n\
    \    operator int() const { return to; }\n    bool operator<(const Edge& o) const{\
    \ return cost < o.cost; }\n};\ntemplate<typename T = int>\nstruct Graph {\n  \
    \  std::vector<std::vector<Edge<T>>> g;\n    int es;\n    Graph() = default;\n\
    \    explicit Graph(int n) : g(n), es(0) {}\n    size_t size() const {\n     \
    \   return g.size();\n    }\n    void add_directed_edge(int from, int to, T cost\
    \ = 1) {\n        g[from].emplace_back(from, to, cost, es++);\n    }\n    void\
    \ add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n \
    \   void read(int M, int padding = -1, bool weighted = false, bool directed =\
    \ false) {\n        for(int i = 0; i < M; i++) {\n            int a, b;\n    \
    \        std::cin >> a >> b;\n            a += padding;\n            b += padding;\n\
    \            T c = T(1);\n            if(weighted) std::cin >> c;\n          \
    \  if(directed) add_directed_edge(a, b, c);\n            else add_edge(a, b, c);\n\
    \        }\n    }\n    inline std::vector<Edge<T>> &operator[](const int &k) {\n\
    \        return g[k];\n    }\n    inline const std::vector<Edge<T>> &operator[](const\
    \ int &k) const {\n        return g[k];\n    }\n};\ntemplate<typename T = int>\n\
    using Edges = std::vector<Edge<T>>;\n#line 4 \"graph/euler-tour.hpp\"\ntemplate<typename\
    \ T>\nstruct EulerTour : Graph<T> {\n  private:\n    struct RMQ {\n        int\
    \ n, s;\n        using P = std::pair<int, int>;\n        std::vector<P> seg;\n\
    \        P UNIT = P(1 << 30, -1);\n        RMQ() = default;\n        void build(const\
    \ std::vector<P> &v) {\n            n = v.size();\n            s = 1;\n      \
    \      while (s < n) s <<= 1;\n            seg.assign(s << 1, UNIT);\n       \
    \     for(int i = 0; i < n; i++) seg[i + s] = v[i];\n            for (int k =\
    \ s - 1; k > 0; k--) {\n                seg[k] = std::min(seg[k << 1], seg[(k\
    \ << 1) + 1]);\n            }\n        }\n        P query(int a, int b) const\
    \ {\n            P R = UNIT;\n            for (a += s, b += s; a < b; a >>= 1,\
    \ b >>= 1) {\n                if (a & 1) R = std::min(R, seg[a++]);\n        \
    \        if (b & 1) R = std::min(R, seg[--b]);\n            }\n            return\
    \ R;\n        }\n        int size() const { return n; }\n    };\n    int cnt;\n\
    \    std::vector<int> dep;\n    std::vector<std::pair<int, int>> idx, rmqvec;\n\
    \    RMQ rmq;\n    void dfs(int v, int p) {\n        idx[v].first = cnt++;\n \
    \       rmqvec.emplace_back(dep[v], v);\n        for(auto &e : g[v]) {\n     \
    \       if(e == p) continue;\n            dep[e] = dep[v] + 1;\n            dfs(e,\
    \ v);\n            rmqvec.emplace_back(dep[v], v);\n        }\n        idx[v].second\
    \ = cnt++;\n    }\n  public:   \n    using Graph<T>::g;\n    EulerTour(int n)\
    \ : Graph<T>(n) {}\n    void build(int root) {\n        idx.assign(g.size(), {-1,\
    \ -1});\n        dep.assign(g.size(), 0);\n        rmqvec.reserve((int)g.size()\
    \ << 1);\n        cnt = 0;\n        dfs(root, -1);\n        rmq.build(rmqvec);\n\
    \    }\n    std::pair<int, int> get_idx(int k) const { return idx[k]; }\n    int\
    \ lca(int u, int v) const {\n        if(idx[u].first > idx[v].first) std::swap(u,\
    \ v);\n        return rmq.query(idx[u].first, idx[v].first + 1).second;\n    }\n\
    \    template<class F>\n    void each_vertex_subtree(int v, const F &f) const\
    \ {\n        f(idx[v].first, idx[v].second + 1);\n    }\n    template<class F>\n\
    \    void each_edge_subtree(int v, const F &f) const {\n        f(idx[v].first\
    \ + 1, idx[v].second + 1);\n    }\n    template<class F>\n    void each_vertex(int\
    \ u, int v, const F &f) const {\n        int l = lca(u, v);\n        f(idx[l].first,\
    \ idx[u].first + 1);\n        f(idx[l].first + 1, idx[v].first + 1);\n    }\n\
    \    template<class F>\n    void each_edge(int u, int v, const F &f) const {\n\
    \        int l = lca(u, v);\n        f(idx[l].first + 1, idx[u].first + 1);\n\
    \        f(idx[l].first + 1, idx[v].first + 1);\n    }\n    int size() const {\
    \ return (int)(g.size()); }\n};\n#line 3 \"data-structure/binary-indexed-tree.hpp\"\
    \n/**\n * @brief BinaryIndexedTree\n**/\ntemplate<typename T>\nstruct BinaryIndexedTree\
    \ {\n  private:\n    int n;\n    std::vector<T> data;\n    T sum(int x) {\n  \
    \      T res = 0;\n        while(x) {\n            res += data[x];\n         \
    \   x -= x & -x;\n        }\n        return res;\n    }\n  public:\n    BinaryIndexedTree()\
    \ : n(0) {}\n    BinaryIndexedTree(int n) : n(n), data(n + 1, 0) {}\n    BinaryIndexedTree(const\
    \ std::vector<T> &v) : n(v.size()), data(v.size() + 1, 0) {\n        for(int i\
    \ = 0; i < n; ++i) add(i, v[i]);\n    }\n    void add(int x, T val) {\n      \
    \  x++;\n        while(x <= n) {\n            data[x] += val;\n            x +=\
    \ x & -x;\n        }\n    }\n    T sum(int l, int r) {\n        return sum(r)\
    \ - sum(l);\n    }\n    T operator[](int x) { return sum(x, x + 1); }\n};\n#line\
    \ 5 \"tests/aoj/GRL_5_D.test.cpp\"\n\nint main() {\n    std::ios::sync_with_stdio(false);\
    \ std::cin.tie(nullptr);\n    int N, Q;\n    std::cin >> N;\n    EulerTour<long\
    \ long> G(N);\n    for(int i = 0; i < N; ++i) {\n        int k; std::cin >> k;\n\
    \        for(int j = 0; j < k; ++j) {\n            int p; std::cin >> p;\n   \
    \         G.add_edge(p, i); \n        }\n    }\n    G.build(0);\n    BinaryIndexedTree<long\
    \ long> bit(2 * N);\n    std::cin >> Q;\n    while(Q--) {\n        int op;\n \
    \       std::cin >> op;\n        if(op == 0) {\n            int p, x;\n      \
    \      std::cin >> p >> x;\n            bit.add(G.get_idx(p).first, x);\n    \
    \        bit.add(G.get_idx(p).second, -x);\n        } else {\n            int\
    \ u;\n            std::cin >> u;\n            long long ans = 0;\n           \
    \ G.each_edge(0, u, [&](int l, int r) { ans += bit.sum(l, r); });\n          \
    \  std::cout << ans << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_D\"\n#include\
    \ <bits/stdc++.h>\n#include \"../../graph/euler-tour.hpp\"\n#include \"../../data-structure/binary-indexed-tree.hpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);\n\
    \    int N, Q;\n    std::cin >> N;\n    EulerTour<long long> G(N);\n    for(int\
    \ i = 0; i < N; ++i) {\n        int k; std::cin >> k;\n        for(int j = 0;\
    \ j < k; ++j) {\n            int p; std::cin >> p;\n            G.add_edge(p,\
    \ i); \n        }\n    }\n    G.build(0);\n    BinaryIndexedTree<long long> bit(2\
    \ * N);\n    std::cin >> Q;\n    while(Q--) {\n        int op;\n        std::cin\
    \ >> op;\n        if(op == 0) {\n            int p, x;\n            std::cin >>\
    \ p >> x;\n            bit.add(G.get_idx(p).first, x);\n            bit.add(G.get_idx(p).second,\
    \ -x);\n        } else {\n            int u;\n            std::cin >> u;\n   \
    \         long long ans = 0;\n            G.each_edge(0, u, [&](int l, int r)\
    \ { ans += bit.sum(l, r); });\n            std::cout << ans << '\\n';\n      \
    \  }\n    }\n}"
  dependsOn:
  - graph/euler-tour.hpp
  - graph/graph-template.hpp
  - data-structure/binary-indexed-tree.hpp
  isVerificationFile: true
  path: tests/aoj/GRL_5_D.test.cpp
  requiredBy: []
  timestamp: '2023-12-18 16:56:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/GRL_5_D.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/GRL_5_D.test.cpp
- /verify/tests/aoj/GRL_5_D.test.cpp.html
title: tests/aoj/GRL_5_D.test.cpp
---
