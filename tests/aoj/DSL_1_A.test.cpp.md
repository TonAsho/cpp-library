---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find.hpp
    title: UnionFind
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
  bundledCode: "#line 1 \"tests/aoj/DSL_1_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n#include <bits/stdc++.h>\n#line 3 \"data-structure/union-find.hpp\"\n/**\n *\
    \ @brief UnionFind\n**/\nstruct UnionFind {\n  private :\n    int n, cnt;\n  \
    \  std::vector<int> ps, sz;\n\n  public :\n    UnionFind(int n) : n(n), cnt(n),\
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
    \  }\n};\n#line 4 \"tests/aoj/DSL_1_A.test.cpp\"\n\nint main() {\n    int N,Q;\n\
    \    std::cin>>N>>Q;\n    UnionFind uni(N);\n    while(Q--){\n        int op,x,y;\n\
    \        std::cin>>op>>x>>y;\n        if(op==0)uni.unite(x,y);\n        else std::cout<<uni.same(x,y)<<std::endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n#include <bits/stdc++.h>\n#include \"data-structure/union-find.hpp\"\n\nint\
    \ main() {\n    int N,Q;\n    std::cin>>N>>Q;\n    UnionFind uni(N);\n    while(Q--){\n\
    \        int op,x,y;\n        std::cin>>op>>x>>y;\n        if(op==0)uni.unite(x,y);\n\
    \        else std::cout<<uni.same(x,y)<<std::endl;\n    }\n}"
  dependsOn:
  - data-structure/union-find.hpp
  isVerificationFile: true
  path: tests/aoj/DSL_1_A.test.cpp
  requiredBy: []
  timestamp: '2024-01-19 15:09:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/DSL_1_A.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/DSL_1_A.test.cpp
- /verify/tests/aoj/DSL_1_A.test.cpp.html
title: tests/aoj/DSL_1_A.test.cpp
---
