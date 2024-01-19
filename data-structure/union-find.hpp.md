---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/kruskal.hpp
    title: Kruskal
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/DSL_1_A.test.cpp
    title: tests/aoj/DSL_1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: UnionFind
    links: []
  bundledCode: "#line 2 \"data-structure/union-find.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @brief UnionFind\n**/\nstruct UnionFind {\n  private :\n    int n, cnt;\n\
    \    std::vector<int> ps, sz;\n\n  public :\n    UnionFind(int n) : n(n), cnt(n),\
    \ ps(n,0), sz(n,1) {\n        for(int i = 0; i < n; ++i) ps[i] = i;\n    }\n \
    \   int leader(int x) {\n        return (ps[x] == x ? x : ps[x] = leader(ps[x]));\n\
    \    }\n    bool same(int x, int y) {\n        return leader(x) == leader(y);\n\
    \    }\n    int unite(int x, int y) {\n        x = leader(x); y = leader(y);\n\
    \        if(x == y) return x;\n        if(sz[x] < sz[y]) std::swap(x, y);\n  \
    \      sz[x] += sz[y];\n        ps[y] = x;\n        cnt--;\n        return x;\n\
    \    }\n    int size(int x) {\n        return sz[leader(x)];\n    }\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<std::vector<int>> res(n);\n        for(int i\
    \ = 0; i < n; ++i) res[leader(i)].push_back(i);\n        res.erase(std::remove_if(res.begin(),\
    \ res.end(), [&](const std::vector<int>& v) {return v.empty();}), res.end());\n\
    \        return res;\n    }\n    int count() const {\n        return cnt;\n  \
    \  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @brief UnionFind\n**/\nstruct\
    \ UnionFind {\n  private :\n    int n, cnt;\n    std::vector<int> ps, sz;\n\n\
    \  public :\n    UnionFind(int n) : n(n), cnt(n), ps(n,0), sz(n,1) {\n       \
    \ for(int i = 0; i < n; ++i) ps[i] = i;\n    }\n    int leader(int x) {\n    \
    \    return (ps[x] == x ? x : ps[x] = leader(ps[x]));\n    }\n    bool same(int\
    \ x, int y) {\n        return leader(x) == leader(y);\n    }\n    int unite(int\
    \ x, int y) {\n        x = leader(x); y = leader(y);\n        if(x == y) return\
    \ x;\n        if(sz[x] < sz[y]) std::swap(x, y);\n        sz[x] += sz[y];\n  \
    \      ps[y] = x;\n        cnt--;\n        return x;\n    }\n    int size(int\
    \ x) {\n        return sz[leader(x)];\n    }\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<std::vector<int>> res(n);\n        for(int i\
    \ = 0; i < n; ++i) res[leader(i)].push_back(i);\n        res.erase(std::remove_if(res.begin(),\
    \ res.end(), [&](const std::vector<int>& v) {return v.empty();}), res.end());\n\
    \        return res;\n    }\n    int count() const {\n        return cnt;\n  \
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/union-find.hpp
  requiredBy:
  - graph/kruskal.hpp
  timestamp: '2024-01-19 15:09:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/DSL_1_A.test.cpp
documentation_of: data-structure/union-find.hpp
layout: document
redirect_from:
- /library/data-structure/union-find.hpp
- /library/data-structure/union-find.hpp.html
title: UnionFind
---
