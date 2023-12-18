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
    document_title: DetectCycle
    links: []
  bundledCode: "#line 2 \"graph/detect-cycle.hpp\"\n#include <bits/stdc++.h>\n#line\
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
    using Edges = std::vector<Edge<T>>;\n#line 4 \"graph/detect-cycle.hpp\"\n/**\n\
    \ * @brief DetectCycle\n */\ntemplate<typename T>\nbool detect_cycle(const Graph<T>\
    \ &g) {\n    const int n = g.size();\n    std::vector<int> deg(n, 0);\n    for(int\
    \ i = 0; i < n; i++) for(auto &e : g[i]) deg[e]++;\n    std::queue<int> q;\n \
    \   for(int i = 0; i < n; i++) if(deg[i] == 0) q.push(i);\n    while(!q.empty())\
    \ {\n        int u = q.front(); q.pop();\n        for(auto &e : g[u]) {\n    \
    \        deg[e]--;\n            if(deg[e] == 0) q.push(e);\n        }\n    }\n\
    \    for(int i = 0; i < n; i++) if(deg[i] != 0) return true;\n    return false;\n\
    }\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"./graph-template.hpp\"\
    \n/**\n * @brief DetectCycle\n */\ntemplate<typename T>\nbool detect_cycle(const\
    \ Graph<T> &g) {\n    const int n = g.size();\n    std::vector<int> deg(n, 0);\n\
    \    for(int i = 0; i < n; i++) for(auto &e : g[i]) deg[e]++;\n    std::queue<int>\
    \ q;\n    for(int i = 0; i < n; i++) if(deg[i] == 0) q.push(i);\n    while(!q.empty())\
    \ {\n        int u = q.front(); q.pop();\n        for(auto &e : g[u]) {\n    \
    \        deg[e]--;\n            if(deg[e] == 0) q.push(e);\n        }\n    }\n\
    \    for(int i = 0; i < n; i++) if(deg[i] != 0) return true;\n    return false;\n\
    }"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: graph/detect-cycle.hpp
  requiredBy: []
  timestamp: '2023-12-18 16:56:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/detect-cycle.hpp
layout: document
redirect_from:
- /library/graph/detect-cycle.hpp
- /library/graph/detect-cycle.hpp.html
title: DetectCycle
---
