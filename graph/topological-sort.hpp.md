---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: Graph Template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/GRL_4_B.test.cpp
    title: tests/aoj/GRL_4_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Topological Sort
    links: []
  bundledCode: "#line 2 \"graph/topological-sort.hpp\"\n#include <bits/stdc++.h>\n\
    #line 3 \"graph/graph-template.hpp\"\n/**\n * @brief Graph Template\n */\ntemplate<typename\
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
    using Edges = std::vector<Edge<T>>;\n#line 4 \"graph/topological-sort.hpp\"\n\
    /**\n * @brief Topological Sort\n */\ntemplate<typename T>\nstruct TopologicalSort\
    \ {\n  private:\n    int n;\n    const Graph<T> &g;\n    std::vector<int> ord;\n\
    \    std::vector<bool> seen;\n    void dfs(int v) {\n        seen[v] = true;\n\
    \        for(auto &e : g[v]) if(!seen[e]) dfs(e);\n        ord.push_back(v);\n\
    \    }\n    void init() {\n        n = g.size();\n        seen.assign(n, false);\n\
    \        ord.reserve(n);\n        for(int i = 0; i < n; ++i) if(!seen[i]) dfs(i);\n\
    \        std::reverse(ord.begin(),ord.end());\n    }\n  public:\n    TopologicalSort(const\
    \ Graph<T> &g) : g(g) { init(); }\n    const std::vector<int> &get() const & {\
    \ return ord; }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"./graph-template.hpp\"\
    \n/**\n * @brief Topological Sort\n */\ntemplate<typename T>\nstruct TopologicalSort\
    \ {\n  private:\n    int n;\n    const Graph<T> &g;\n    std::vector<int> ord;\n\
    \    std::vector<bool> seen;\n    void dfs(int v) {\n        seen[v] = true;\n\
    \        for(auto &e : g[v]) if(!seen[e]) dfs(e);\n        ord.push_back(v);\n\
    \    }\n    void init() {\n        n = g.size();\n        seen.assign(n, false);\n\
    \        ord.reserve(n);\n        for(int i = 0; i < n; ++i) if(!seen[i]) dfs(i);\n\
    \        std::reverse(ord.begin(),ord.end());\n    }\n  public:\n    TopologicalSort(const\
    \ Graph<T> &g) : g(g) { init(); }\n    const std::vector<int> &get() const & {\
    \ return ord; }\n};"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: graph/topological-sort.hpp
  requiredBy: []
  timestamp: '2024-01-20 10:08:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/GRL_4_B.test.cpp
documentation_of: graph/topological-sort.hpp
layout: document
redirect_from:
- /library/graph/topological-sort.hpp
- /library/graph/topological-sort.hpp.html
title: Topological Sort
---
