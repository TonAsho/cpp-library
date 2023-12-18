---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/binary-indexed-tree.hpp
    title: BinaryIndexedTree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B
  bundledCode: "#line 1 \"tests/aoj/DSL_2_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B\"\
    \n#include <bits/stdc++.h>\n#line 3 \"data-structure/binary-indexed-tree.hpp\"\
    \n/**\n * @brief BinaryIndexedTree\n**/\ntemplate<typename T>\nstruct BinaryIndexedTree\
    \ {\n  private:\n    int n;\n    std::vector<T> data;\n    T sum(int x) {\n  \
    \      T res = 0;\n        while(x) {\n            res += data[x];\n         \
    \   x -= x & -x;\n        }\n        return res;\n    }\n  public:\n    BinaryIndexedTree()\
    \ : n(0) {}\n    BinaryIndexedTree(int n) : n(n), data(n + 1, 0) {}\n    BinaryIndexedTree(const\
    \ std::vector<T> &v) : n(v.size()), data(v.size() + 1, 0) {\n        for(int i\
    \ = 0; i < n; ++i) add(i, v[i]);\n    }\n    void add(int x, T val) {\n      \
    \  x++;\n        while(x <= n) {\n            data[x] += val;\n            x +=\
    \ x & -x;\n        }\n    }\n    T sum(int l, int r) {\n        return sum(r)\
    \ - sum(l);\n    }\n    T operator[](int x) { return sum(x, x + 1); }\n};\n#line\
    \ 4 \"tests/aoj/DSL_2_B.test.cpp\"\n\nint main() {\n    std::ios::sync_with_stdio(false);\
    \ std::cin.tie(nullptr);\n    int N, Q;\n    std::cin >> N >> Q;\n    BinaryIndexedTree<long\
    \ long> bit(N + 1);\n    while(Q--) {\n        int t, x, y;\n        std::cin\
    \ >> t >> x >> y;\n        if(t == 0) {\n            bit.add(x, y);\n        }\
    \ else {\n            std::cout << bit.sum(x, y + 1) << std::endl;\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B\"\n#include\
    \ <bits/stdc++.h>\n#include \"../../data-structure/binary-indexed-tree.hpp\"\n\
    \nint main() {\n    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);\n\
    \    int N, Q;\n    std::cin >> N >> Q;\n    BinaryIndexedTree<long long> bit(N\
    \ + 1);\n    while(Q--) {\n        int t, x, y;\n        std::cin >> t >> x >>\
    \ y;\n        if(t == 0) {\n            bit.add(x, y);\n        } else {\n   \
    \         std::cout << bit.sum(x, y + 1) << std::endl;\n        }\n    }\n}"
  dependsOn:
  - data-structure/binary-indexed-tree.hpp
  isVerificationFile: true
  path: tests/aoj/DSL_2_B.test.cpp
  requiredBy: []
  timestamp: '2023-12-18 16:56:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/DSL_2_B.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/DSL_2_B.test.cpp
- /verify/tests/aoj/DSL_2_B.test.cpp.html
title: tests/aoj/DSL_2_B.test.cpp
---
