---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/bellman-ford.hpp
    title: Bellman-Ford
  - icon: ':warning:'
    path: graph/detect-cycle.hpp
    title: DetectCycle
  - icon: ':warning:'
    path: graph/dijkstra.hpp
    title: Dijkstra
  - icon: ':heavy_check_mark:'
    path: graph/euler-tour.hpp
    title: EulerTour
  - icon: ':warning:'
    path: graph/lca.hpp
    title: LCA
  - icon: ':warning:'
    path: tests/yosupo/vertex_add_path_sum.tset.cpp
    title: tests/yosupo/vertex_add_path_sum.tset.cpp
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
    path: tests/yosupo/vertex_add_subtree_sum.test.cpp
    title: tests/yosupo/vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Graph Template
    links: []
  bundledCode: "#line 2 \"graph/graph-template.hpp\"\n#include <bits/stdc++.h>\n/**\n\
    \ * @brief Graph Template\n */\ntemplate<typename T = int>\nstruct Edge {\n  \
    \  int from, to;\n    T cost;\n    int idx;\n    Edge() = default;\n    Edge(int\
    \ from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx)\
    \ {}\n    operator int() const { return to; }\n    bool operator<(const Edge&\
    \ o) const{ return cost < o.cost; }\n};\ntemplate<typename T = int>\nstruct Graph\
    \ {\n    std::vector<std::vector<Edge<T>>> g;\n    int es;\n    Graph() = default;\n\
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
    using Edges = std::vector<Edge<T>>;\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @brief Graph Template\n */\n\
    template<typename T = int>\nstruct Edge {\n    int from, to;\n    T cost;\n  \
    \  int idx;\n    Edge() = default;\n    Edge(int from, int to, T cost = 1, int\
    \ idx = -1) : from(from), to(to), cost(cost), idx(idx) {}\n    operator int()\
    \ const { return to; }\n    bool operator<(const Edge& o) const{ return cost <\
    \ o.cost; }\n};\ntemplate<typename T = int>\nstruct Graph {\n    std::vector<std::vector<Edge<T>>>\
    \ g;\n    int es;\n    Graph() = default;\n    explicit Graph(int n) : g(n), es(0)\
    \ {}\n    size_t size() const {\n        return g.size();\n    }\n    void add_directed_edge(int\
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
    using Edges = std::vector<Edge<T>>;"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph-template.hpp
  requiredBy:
  - graph/euler-tour.hpp
  - graph/lca.hpp
  - graph/detect-cycle.hpp
  - graph/bellman-ford.hpp
  - graph/dijkstra.hpp
  - tests/yosupo/vertex_add_path_sum.tset.cpp
  timestamp: '2023-12-18 16:56:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/vertex_add_subtree_sum.test.cpp
  - tests/yosupo/lca_euler_tour.test.cpp
  - tests/aoj/GRL_5_C.test.cpp
  - tests/aoj/GRL_5_D.test.cpp
documentation_of: graph/graph-template.hpp
layout: document
redirect_from:
- /library/graph/graph-template.hpp
- /library/graph/graph-template.hpp.html
title: Graph Template
---
