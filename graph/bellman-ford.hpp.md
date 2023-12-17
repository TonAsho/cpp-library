---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph/graph-template.hpp
    title: Graph Template
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Bellman-Ford
    links: []
  bundledCode: "#line 2 \"graph/bellman-ford.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"template/alias.hpp\"\n\nusing ll = long long;\nusing ull = unsigned long\
    \ long;\nusing ld = long double;\nusing vi = std::vector<int>;\nusing vvi = std::vector<vi>;\n\
    using vl = std::vector<ll>;\nusing vvl = std::vector<vl>;\nusing vd = std::vector<double>;\n\
    using vvd = std::vector<vd>;\nusing vs = std::vector<std::string>;\nusing vvs\
    \ = std::vector<vs>;\nusing vb = std::vector<bool>;\nusing vvb = std::vector<vb>;\n\
    using vc = std::vector<char>;\nusing vvc = std::vector<vc>;\nusing pii = std::pair<int,\
    \ int>;\nusing pll = std::pair<ll, ll>;\nusing mii = std::map<int, int>;\nusing\
    \ mll = std::map<ll, ll>;\ntemplate<typename T>\nstruct infinity{\n    static\
    \ constexpr T max=std::numeric_limits<T>::max();\n    static constexpr T min=std::numeric_limits<T>::min();\n\
    \    static constexpr T value=std::numeric_limits<T>::max()/2;\n    static constexpr\
    \ T mvalue=std::numeric_limits<T>::min()/2;\n};\ntemplate<typename T>constexpr\
    \ T INF=infinity<T>::value;\nconstexpr ll infl=INF<ll>;\nconstexpr int inf = INF<int>;\n\
    constexpr ld PI = 3.1415926535897932384626;\n#line 3 \"graph/graph-template.hpp\"\
    \n/**\n * @brief Graph Template\n */\ntemplate< typename T = int >\nstruct Edge\
    \ {\n    int from, to;\n    T cost;\n    int idx;\n    Edge() = default;\n   \
    \ Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost),\
    \ idx(idx) {}\n    operator int() const { return to; }\n    bool operator<(const\
    \ Edge& o) const{return cost<o.cost;}\n};\ntemplate< typename T = int >\nstruct\
    \ Graph {\n    std::vector< std::vector< Edge< T > > > g;\n    int es;\n    Graph()\
    \ = default;\n    explicit Graph(int n) : g(n), es(0) {}\n    size_t size() const\
    \ {\n        return g.size();\n    }\n    void add_directed_edge(int from, int\
    \ to, T cost = 1) {\n        g[from].emplace_back(from, to, cost, es++);\n   \
    \ }\n    void add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n \
    \   void read(int M, int padding = -1, bool weighted = false, bool directed =\
    \ false) {\n        for(int i = 0; i < M; i++) {\n        int a, b;\n        cin\
    \ >> a >> b;\n        a += padding;\n        b += padding;\n        T c = T(1);\n\
    \        if(weighted) cin >> c;\n        if(directed) add_directed_edge(a, b,\
    \ c);\n        else add_edge(a, b, c);\n        }\n    }\n    inline std::vector<\
    \ Edge< T > > &operator[](const int &k) {\n        return g[k];\n    }\n    inline\
    \ const std::vector< Edge< T > > &operator[](const int &k) const {\n        return\
    \ g[k];\n    }\n};\ntemplate< typename T = int >\nusing Edges = std::vector< Edge<\
    \ T > >;\n#line 5 \"graph/bellman-ford.hpp\"\n/**\n * @brief Bellman-Ford\n */\n\
    template< typename T >\nstd::vector<T> bellman_ford(const Edges< T > &edges, int\
    \ V, int s) {\n    std::vector< T > dist(V, INF<T>);\n    dist[s] = 0;\n    for(int\
    \ i = 0; i < V - 1; i++) {\n        for(auto &e : edges) {\n        if(dist[e.from]\
    \ == INF) continue;\n            dist[e.to] = min(dist[e.to], dist[e.from] + e.cost);\n\
    \        }\n    }\n    for(auto &e : edges) {\n        if(dist[e.from] == INF)\
    \ continue;\n        if(dist[e.from] + e.cost < dist[e.to]) return std::vector<T>();\n\
    \    }\n    return dist;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"../template/alias.hpp\"\
    \n#include \"./graph-template.hpp\"\n/**\n * @brief Bellman-Ford\n */\ntemplate<\
    \ typename T >\nstd::vector<T> bellman_ford(const Edges< T > &edges, int V, int\
    \ s) {\n    std::vector< T > dist(V, INF<T>);\n    dist[s] = 0;\n    for(int i\
    \ = 0; i < V - 1; i++) {\n        for(auto &e : edges) {\n        if(dist[e.from]\
    \ == INF) continue;\n            dist[e.to] = min(dist[e.to], dist[e.from] + e.cost);\n\
    \        }\n    }\n    for(auto &e : edges) {\n        if(dist[e.from] == INF)\
    \ continue;\n        if(dist[e.from] + e.cost < dist[e.to]) return std::vector<T>();\n\
    \    }\n    return dist;\n}"
  dependsOn:
  - template/alias.hpp
  - graph/graph-template.hpp
  isVerificationFile: false
  path: graph/bellman-ford.hpp
  requiredBy: []
  timestamp: '2023-12-17 11:32:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bellman-ford.hpp
layout: document
redirect_from:
- /library/graph/bellman-ford.hpp
- /library/graph/bellman-ford.hpp.html
title: Bellman-Ford
---
