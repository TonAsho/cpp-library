---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find.hpp
    title: UnionFind
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Kruskal
    links: []
  bundledCode: "#line 2 \"graph/kruskal.hpp\"\n#include <bits/stdc++.h>\n#line 3 \"\
    data-structure/union-find.hpp\"\n/**\n * @brief UnionFind\n**/\nstruct UnionFind\
    \ {\n  private :\n    int n, cnt;\n    std::vector<int> ps, sz;\n\n  public :\n\
    \    UnionFind(int n) : n(n), cnt(n), ps(n,0), sz(n,1) {\n        for(int i =\
    \ 0; i < n; ++i) ps[i] = i;\n    }\n    int leader(int x) {\n        return (ps[x]\
    \ == x ? x : ps[x] = leader(ps[x]));\n    }\n    bool same(int x, int y) {\n \
    \       return leader(x) == leader(y);\n    }\n    int unite(int x, int y) {\n\
    \        x = leader(x); y = leader(y);\n        if(x == y) return x;\n       \
    \ if(sz[x] < sz[y]) std::swap(x, y);\n        sz[x] += sz[y];\n        ps[y] =\
    \ x;\n        cnt--;\n        return x;\n    }\n    int size(int x) {\n      \
    \  return sz[leader(x)];\n    }\n    std::vector<std::vector<int>> groups() {\n\
    \        std::vector<std::vector<int>> res(n);\n        for(int i = 0; i < n;\
    \ ++i) res[leader(i)].push_back(i);\n        res.erase(std::remove_if(res.begin(),\
    \ res.end(), [&](const std::vector<int>& v) {return v.empty();}), res.end());\n\
    \        return res;\n    }\n    int count() const {\n        return cnt;\n  \
    \  }\n};\n#line 4 \"graph/kruskal.hpp\"\n/**\n * @brief Kruskal\n */\ntemplate<class\
    \ T>\nstruct Kruskal : UnionFind {\n    using UnionFind::UnionFind;\n    struct\
    \ Edge {\n        int from, to;\n        T cost;\n        int used;\n        int\
    \ idx;\n        Edge() = default;\n        Edge(int from, int to, T cost = 1,\
    \ int idx = -1) : from(from), to(to), used(0), cost(cost), idx(idx) {}\n     \
    \   bool operator<(const Edge& o) const{return cost<o.cost;}\n    };\n    std::vector<Edge>\
    \ es;\n    void add_edge(int u, int v, T c) {\n        es.emplace_back(u, v, c);\n\
    \    }\n    T build() {\n        sort(es.begin(), es.end());\n        T res =\
    \ 0;\n        for(auto &e : es) {\n            if(same(e.from, e.to)) continue;\n\
    \            unite(e.from, e.to);\n            res += e.cost;\n            e.used\
    \ = 1;\n        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"../data-structure/union-find.hpp\"\
    \n/**\n * @brief Kruskal\n */\ntemplate<class T>\nstruct Kruskal : UnionFind {\n\
    \    using UnionFind::UnionFind;\n    struct Edge {\n        int from, to;\n \
    \       T cost;\n        int used;\n        int idx;\n        Edge() = default;\n\
    \        Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to),\
    \ used(0), cost(cost), idx(idx) {}\n        bool operator<(const Edge& o) const{return\
    \ cost<o.cost;}\n    };\n    std::vector<Edge> es;\n    void add_edge(int u, int\
    \ v, T c) {\n        es.emplace_back(u, v, c);\n    }\n    T build() {\n     \
    \   sort(es.begin(), es.end());\n        T res = 0;\n        for(auto &e : es)\
    \ {\n            if(same(e.from, e.to)) continue;\n            unite(e.from, e.to);\n\
    \            res += e.cost;\n            e.used = 1;\n        }\n        return\
    \ res;\n    }\n};\n"
  dependsOn:
  - data-structure/union-find.hpp
  isVerificationFile: false
  path: graph/kruskal.hpp
  requiredBy: []
  timestamp: '2024-01-19 15:09:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/kruskal.hpp
layout: document
redirect_from:
- /library/graph/kruskal.hpp
- /library/graph/kruskal.hpp.html
title: Kruskal
---