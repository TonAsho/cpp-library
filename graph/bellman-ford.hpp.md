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
    document_title: Bellman-Ford
    links: []
  bundledCode: "#line 2 \"graph/bellman-ford.hpp\"\n#include <bits/stdc++.h>\n#line\
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
    using Edges = std::vector<Edge<T>>;\n#line 4 \"graph/bellman-ford.hpp\"\n/**\n\
    \ * @brief Bellman-Ford\n */\ntemplate<typename T>\nstd::vector<T> bellman_ford(const\
    \ Graph<T> &g, int s) {\n    const int n = g.size();\n    const T MAX = std::numeric_limits<T>::max()\
    \ / 2;\n    std::vector<T> d(n, MAX);\n    d[s] = 0;\n    for(int i = 0; i < n;\
    \ i++) {\n        bool changed = false;\n        for(int j = 0; j < n; j++) {\n\
    \            for(auto &e : g[j]) {\n                if(d[j] != MAX && d[e] > d[j]\
    \ + e.cost) {\n                    d[e] = d[j] + e.cost;\n                   \
    \ changed = true;\n                }\n            }\n        }\n        if(!changed)\
    \ return d;\n    }\n    for(int i = 0; i < n; i++) {\n        for(auto &e : g[i])\
    \ {\n            if(d[i] != MAX && d[e] > d[i] + e.cost) d[e] = -MAX;\n      \
    \  }\n    }\n    for(int i = 0; i < n - 1; i++){\n        bool changed=false;\n\
    \        for(int j = 0; j < n; j++){\n            if(d[j] != -MAX) continue;\n\
    \            for(auto &e : g[j]){\n                if(d[e] != -MAX){\n       \
    \             d[e] = d[j];\n                    changed = true;\n            \
    \    }\n            }\n        }\n        if(!changed)break;\n    }\n    return\
    \ d;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"./graph-template.hpp\"\
    \n/**\n * @brief Bellman-Ford\n */\ntemplate<typename T>\nstd::vector<T> bellman_ford(const\
    \ Graph<T> &g, int s) {\n    const int n = g.size();\n    const T MAX = std::numeric_limits<T>::max()\
    \ / 2;\n    std::vector<T> d(n, MAX);\n    d[s] = 0;\n    for(int i = 0; i < n;\
    \ i++) {\n        bool changed = false;\n        for(int j = 0; j < n; j++) {\n\
    \            for(auto &e : g[j]) {\n                if(d[j] != MAX && d[e] > d[j]\
    \ + e.cost) {\n                    d[e] = d[j] + e.cost;\n                   \
    \ changed = true;\n                }\n            }\n        }\n        if(!changed)\
    \ return d;\n    }\n    for(int i = 0; i < n; i++) {\n        for(auto &e : g[i])\
    \ {\n            if(d[i] != MAX && d[e] > d[i] + e.cost) d[e] = -MAX;\n      \
    \  }\n    }\n    for(int i = 0; i < n - 1; i++){\n        bool changed=false;\n\
    \        for(int j = 0; j < n; j++){\n            if(d[j] != -MAX) continue;\n\
    \            for(auto &e : g[j]){\n                if(d[e] != -MAX){\n       \
    \             d[e] = d[j];\n                    changed = true;\n            \
    \    }\n            }\n        }\n        if(!changed)break;\n    }\n    return\
    \ d;\n}"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: graph/bellman-ford.hpp
  requiredBy: []
  timestamp: '2023-12-18 16:56:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bellman-ford.hpp
layout: document
redirect_from:
- /library/graph/bellman-ford.hpp
- /library/graph/bellman-ford.hpp.html
title: Bellman-Ford
---
