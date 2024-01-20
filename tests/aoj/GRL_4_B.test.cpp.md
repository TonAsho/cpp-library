---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: Graph Template
  - icon: ':heavy_check_mark:'
    path: graph/topological-sort.hpp
    title: Topological Sort
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_B
  bundledCode: "#line 1 \"tests/aoj/GRL_4_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_B\"\
    \n#include <bits/stdc++.h>\n#line 3 \"graph/graph-template.hpp\"\n/**\n * @brief\
    \ Graph Template\n */\ntemplate<typename T = int>\nstruct Edge {\n    int from,\
    \ to;\n    T cost;\n    int idx;\n    Edge() = default;\n    Edge(int from, int\
    \ to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}\n\
    \    operator int() const { return to; }\n    bool operator<(const Edge& o) const{\
    \ return cost < o.cost; }\n};\ntemplate<typename T = int>\nstruct Graph {\n  \
    \  std::vector<std::vector<Edge<T>>> g;\n    int es;\n    Graph() = default;\n\
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
    using Edges = std::vector<Edge<T>>;\n#line 4 \"graph/topological-sort.hpp\"\n\
    /**\n * @brief Topological Sort\n */\ntemplate<typename T>\nstruct TopologicalSort\
    \ {\n  private:\n    int n;\n    const Graph<T> &g;\n    std::vector<int> ord;\n\
    \    std::vector<bool> seen;\n    void dfs(int v) {\n        seen[v] = true;\n\
    \        for(auto &e : g[v]) if(!seen[e]) dfs(e);\n        ord.push_back(v);\n\
    \    }\n    void init() {\n        n = g.size();\n        seen.assign(n, false);\n\
    \        ord.reserve(n);\n        for(int i = 0; i < n; ++i) if(!seen[i]) dfs(i);\n\
    \        std::reverse(ord.begin(),ord.end());\n    }\n  public:\n    TopologicalSort(const\
    \ Graph<T> &g) : g(g) { init(); }\n    const std::vector<int> &get() const & {\
    \ return ord; }\n};\n#line 4 \"tests/aoj/GRL_4_B.test.cpp\"\n\nint main(){\n \
    \   int N,M;\n    std::cin>>N>>M;\n    Graph<int> G(N);\n    G.read(M,0,false,true);\n\
    \    std::vector<int> ans=std::move(TopologicalSort<int>(G).get());\n    for(int\
    \ i = 0; i < ans.size(); ++i) std::cout<<ans[i]<<'\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_B\"\n#include\
    \ <bits/stdc++.h>\n#include \"graph/topological-sort.hpp\"\n\nint main(){\n  \
    \  int N,M;\n    std::cin>>N>>M;\n    Graph<int> G(N);\n    G.read(M,0,false,true);\n\
    \    std::vector<int> ans=std::move(TopologicalSort<int>(G).get());\n    for(int\
    \ i = 0; i < ans.size(); ++i) std::cout<<ans[i]<<'\\n';\n}"
  dependsOn:
  - graph/topological-sort.hpp
  - graph/graph-template.hpp
  isVerificationFile: true
  path: tests/aoj/GRL_4_B.test.cpp
  requiredBy: []
  timestamp: '2024-01-20 10:08:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/GRL_4_B.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/GRL_4_B.test.cpp
- /verify/tests/aoj/GRL_4_B.test.cpp.html
title: tests/aoj/GRL_4_B.test.cpp
---
