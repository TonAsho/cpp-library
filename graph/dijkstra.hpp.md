---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: Graph Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Dijkstra
    links: []
  bundledCode: "#line 2 \"graph/dijkstra.hpp\"\n#include <bits/stdc++.h>\n#line 3\
    \ \"graph/graph-template.hpp\"\n/**\n * @brief Graph Template\n */\ntemplate<typename\
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
    using Edges = std::vector<Edge<T>>;\n#line 4 \"graph/dijkstra.hpp\"\n/**\n * @brief\
    \ Dijkstra\n */\ntemplate< typename T >\nstruct Dijkstra : Graph<T> {\n  private:\n\
    \    using P = std::pair<T, int>;\n    const T MAX = std::numeric_limits<T>::max()\
    \ / 2;\n    int from;\n    std::vector<T> d, prev;\n  public:\n    using Graph<T>::g;\n\
    \    Dijkstra(int n) : Graph<T>(n) {}\n    void build(int from) {\n        this->from\
    \ = from;\n        d.assign(g.size(), MAX);\n        prev.assign(g.size(), 0);\n\
    \        d[from] = 0;\n        std::priority_queue<P, std::vector<P>, std::greater<P>>\
    \ q;\n        q.emplace(0, from);\n        while(!q.empty()) {\n            auto\
    \ [d_u, u] = q.top(); q.pop();\n            if(d[u] < d_u) continue;\n       \
    \     for(auto &e : g[u]) {\n                if(d[e] > d[u] + e.cost) {\n    \
    \                d[e] = d[u] + e.cost;\n                    prev[e] = u;\n   \
    \                 q.emplace(d[e], e);\n                }\n            }\n    \
    \    }\n    }\n    T dist(int to) {\n        assert(0 <= to && to < (int)d.size());\n\
    \        return d[to];\n    }\n    std::vector<int> path(int to) {\n        assert(0\
    \ <= to && to < (int)d.size());\n        if(d[to] == MAX) return {};\n       \
    \ std::vector<int> path = {to};\n        while(path.back() != from) path.emplace_back(prev[path.back()]);\n\
    \        reverse(path.begin(), path.end());\n        return path;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"./graph-template.hpp\"\
    \n/**\n * @brief Dijkstra\n */\ntemplate< typename T >\nstruct Dijkstra : Graph<T>\
    \ {\n  private:\n    using P = std::pair<T, int>;\n    const T MAX = std::numeric_limits<T>::max()\
    \ / 2;\n    int from;\n    std::vector<T> d, prev;\n  public:\n    using Graph<T>::g;\n\
    \    Dijkstra(int n) : Graph<T>(n) {}\n    void build(int from) {\n        this->from\
    \ = from;\n        d.assign(g.size(), MAX);\n        prev.assign(g.size(), 0);\n\
    \        d[from] = 0;\n        std::priority_queue<P, std::vector<P>, std::greater<P>>\
    \ q;\n        q.emplace(0, from);\n        while(!q.empty()) {\n            auto\
    \ [d_u, u] = q.top(); q.pop();\n            if(d[u] < d_u) continue;\n       \
    \     for(auto &e : g[u]) {\n                if(d[e] > d[u] + e.cost) {\n    \
    \                d[e] = d[u] + e.cost;\n                    prev[e] = u;\n   \
    \                 q.emplace(d[e], e);\n                }\n            }\n    \
    \    }\n    }\n    T dist(int to) {\n        assert(0 <= to && to < (int)d.size());\n\
    \        return d[to];\n    }\n    std::vector<int> path(int to) {\n        assert(0\
    \ <= to && to < (int)d.size());\n        if(d[to] == MAX) return {};\n       \
    \ std::vector<int> path = {to};\n        while(path.back() != from) path.emplace_back(prev[path.back()]);\n\
    \        reverse(path.begin(), path.end());\n        return path;\n    }\n};"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2023-12-18 16:56:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: Dijkstra
---