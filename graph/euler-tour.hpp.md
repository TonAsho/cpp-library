---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: Graph Template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/GRL_5_C.test.cpp
    title: tests/aoj/GRL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/aoj/GRL_5_D.test.cpp
    title: tests/aoj/GRL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/lca_euler_tour.test.cpp
    title: tests/yosupo/lca_euler_tour.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/vertex_add_path_sum.test.cpp
    title: tests/yosupo/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/vertex_add_subtree_sum.test.cpp
    title: tests/yosupo/vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: EulerTour
    links: []
  bundledCode: "#line 2 \"graph/euler-tour.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"graph/graph-template.hpp\"\n/**\n * @brief Graph Template\n */\ntemplate<typename\
    \ T = int>\nstruct Edge {\n    int from, to;\n    T cost;\n    int idx;\n    Edge()\
    \ = default;\n    Edge(int from, int to, T cost = 1, int idx = -1) : from(from),\
    \ to(to), cost(cost), idx(idx) {}\n    operator int() const { return to; }\n \
    \   bool operator<(const Edge& o) const{ return cost < o.cost; }\n};\ntemplate<typename\
    \ T = int>\nstruct Graph {\n    std::vector<std::vector<Edge<T>>> g;\n    int\
    \ es;\n    Graph() = default;\n    explicit Graph(int n) : g(n), es(0) {}\n  \
    \  size_t size() const {\n        return g.size();\n    }\n    void add_directed_edge(int\
    \ from, int to, T cost = 1) {\n        g[from].emplace_back(from, to, cost, es++);\n\
    \    }\n    void add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n \
    \   void read(int M, int padding = -1, bool weighted = false, bool directed =\
    \ false) {\n        for(int i = 0; i < M; i++) {\n            int a, b;\n    \
    \        std::cin >> a >> b;\n            a += padding;\n            b += padding;\n\
    \            T c = T(1);\n            if(weighted) std::cin >> c;\n          \
    \  if(directed) add_directed_edge(a, b, c);\n            else add_edge(a, b, c);\n\
    \        }\n    }\n    inline std::vector<Edge<T>> &operator[](const int &k) {\n\
    \        return g[k];\n    }\n    inline const std::vector<Edge<T>> &operator[](const\
    \ int &k) const {\n        return g[k];\n    }\n};\ntemplate<typename T = int>\n\
    using Edges = std::vector<Edge<T>>;\n#line 4 \"graph/euler-tour.hpp\"\n/**\n *\
    \ @brief EulerTour\n */\ntemplate<typename T>\nstruct EulerTour : Graph<T> {\n\
    \  private:\n    struct RMQ {\n        int n, s;\n        using P = std::pair<int,\
    \ int>;\n        std::vector<P> seg;\n        P UNIT = P(1 << 30, -1);\n     \
    \   RMQ() = default;\n        void build(const std::vector<P> &v) {\n        \
    \    n = v.size();\n            s = 1;\n            while (s < n) s <<= 1;\n \
    \           seg.assign(s << 1, UNIT);\n            for(int i = 0; i < n; i++)\
    \ seg[i + s] = v[i];\n            for (int k = s - 1; k > 0; k--) {\n        \
    \        seg[k] = std::min(seg[k << 1], seg[(k << 1) + 1]);\n            }\n \
    \       }\n        P query(int a, int b) const {\n            P R = UNIT;\n  \
    \          for (a += s, b += s; a < b; a >>= 1, b >>= 1) {\n                if\
    \ (a & 1) R = std::min(R, seg[a++]);\n                if (b & 1) R = std::min(R,\
    \ seg[--b]);\n            }\n            return R;\n        }\n        int size()\
    \ const { return n; }\n    };\n    int cnt;\n    std::vector<int> dep;\n    std::vector<std::pair<int,\
    \ int>> idx, rmqvec;\n    RMQ rmq;\n    void dfs(int v, int p) {\n        idx[v].first\
    \ = cnt++;\n        rmqvec.emplace_back(dep[v], v);\n        for(auto &e : g[v])\
    \ {\n            if(e == p) continue;\n            dep[e] = dep[v] + 1;\n    \
    \        dfs(e, v);\n            rmqvec.emplace_back(dep[v], v);\n        }\n\
    \        idx[v].second = cnt++;\n    }\n  public:   \n    using Graph<T>::g;\n\
    \    EulerTour(int n) : Graph<T>(n) {}\n    void build(int root) {\n        idx.assign(g.size(),\
    \ {-1, -1});\n        dep.assign(g.size(), 0);\n        rmqvec.reserve((int)g.size()\
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
    \ return (int)(g.size()); }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"graph/graph-template.hpp\"\
    \n/**\n * @brief EulerTour\n */\ntemplate<typename T>\nstruct EulerTour : Graph<T>\
    \ {\n  private:\n    struct RMQ {\n        int n, s;\n        using P = std::pair<int,\
    \ int>;\n        std::vector<P> seg;\n        P UNIT = P(1 << 30, -1);\n     \
    \   RMQ() = default;\n        void build(const std::vector<P> &v) {\n        \
    \    n = v.size();\n            s = 1;\n            while (s < n) s <<= 1;\n \
    \           seg.assign(s << 1, UNIT);\n            for(int i = 0; i < n; i++)\
    \ seg[i + s] = v[i];\n            for (int k = s - 1; k > 0; k--) {\n        \
    \        seg[k] = std::min(seg[k << 1], seg[(k << 1) + 1]);\n            }\n \
    \       }\n        P query(int a, int b) const {\n            P R = UNIT;\n  \
    \          for (a += s, b += s; a < b; a >>= 1, b >>= 1) {\n                if\
    \ (a & 1) R = std::min(R, seg[a++]);\n                if (b & 1) R = std::min(R,\
    \ seg[--b]);\n            }\n            return R;\n        }\n        int size()\
    \ const { return n; }\n    };\n    int cnt;\n    std::vector<int> dep;\n    std::vector<std::pair<int,\
    \ int>> idx, rmqvec;\n    RMQ rmq;\n    void dfs(int v, int p) {\n        idx[v].first\
    \ = cnt++;\n        rmqvec.emplace_back(dep[v], v);\n        for(auto &e : g[v])\
    \ {\n            if(e == p) continue;\n            dep[e] = dep[v] + 1;\n    \
    \        dfs(e, v);\n            rmqvec.emplace_back(dep[v], v);\n        }\n\
    \        idx[v].second = cnt++;\n    }\n  public:   \n    using Graph<T>::g;\n\
    \    EulerTour(int n) : Graph<T>(n) {}\n    void build(int root) {\n        idx.assign(g.size(),\
    \ {-1, -1});\n        dep.assign(g.size(), 0);\n        rmqvec.reserve((int)g.size()\
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
    \ return (int)(g.size()); }\n};"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: graph/euler-tour.hpp
  requiredBy: []
  timestamp: '2023-12-19 23:17:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/GRL_5_C.test.cpp
  - tests/aoj/GRL_5_D.test.cpp
  - tests/yosupo/vertex_add_path_sum.test.cpp
  - tests/yosupo/lca_euler_tour.test.cpp
  - tests/yosupo/vertex_add_subtree_sum.test.cpp
documentation_of: graph/euler-tour.hpp
layout: document
redirect_from:
- /library/graph/euler-tour.hpp
- /library/graph/euler-tour.hpp.html
title: EulerTour
---