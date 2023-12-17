---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/inversion-number.hpp
    title: Inversion Number
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: BinaryIndexedTree
    links: []
  bundledCode: "#line 2 \"data-structure/binary-indexed-tree.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @brief BinaryIndexedTree\n**/\ntemplate<typename T>\nstruct BinaryIndexedTree\
    \ {\n  private:\n    int n;\n    std::vector<T> data;\n    T sum(int x) {\n  \
    \      T res = 0;\n        while(x) {\n            res += data[x];\n         \
    \   x -= x & -x;\n        }\n        return res;\n    }\n  public:\n    BinaryIndexedTree()\
    \ : n(0) {}\n    BinaryIndexedTree(int n) : n(n), data(n + 1, 0) {}\n    BinaryIndexedTree(const\
    \ std::vector<T> &v) : n(v.size()), data(v.size() + 1, 0) {\n        for(int i\
    \ = 0; i < n; ++i) add(i, v[i]);\n    }\n    void add(int x, T val) {\n      \
    \  x++;\n        while(x <= n) {\n            data[x] += val;\n            x +=\
    \ x & -x;\n        }\n    }\n    T sum(int l, int r) {\n        return sum(r)\
    \ - sum(l);\n    }\n    T operator[](int x) const { return sum(x, x + 1); }\n\
    };\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @brief BinaryIndexedTree\n\
    **/\ntemplate<typename T>\nstruct BinaryIndexedTree {\n  private:\n    int n;\n\
    \    std::vector<T> data;\n    T sum(int x) {\n        T res = 0;\n        while(x)\
    \ {\n            res += data[x];\n            x -= x & -x;\n        }\n      \
    \  return res;\n    }\n  public:\n    BinaryIndexedTree() : n(0) {}\n    BinaryIndexedTree(int\
    \ n) : n(n), data(n + 1, 0) {}\n    BinaryIndexedTree(const std::vector<T> &v)\
    \ : n(v.size()), data(v.size() + 1, 0) {\n        for(int i = 0; i < n; ++i) add(i,\
    \ v[i]);\n    }\n    void add(int x, T val) {\n        x++;\n        while(x <=\
    \ n) {\n            data[x] += val;\n            x += x & -x;\n        }\n   \
    \ }\n    T sum(int l, int r) {\n        return sum(r) - sum(l);\n    }\n    T\
    \ operator[](int x) const { return sum(x, x + 1); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binary-indexed-tree.hpp
  requiredBy:
  - data-structure/inversion-number.hpp
  timestamp: '2023-12-17 11:32:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/binary-indexed-tree.hpp
layout: document
redirect_from:
- /library/data-structure/binary-indexed-tree.hpp
- /library/data-structure/binary-indexed-tree.hpp.html
title: BinaryIndexedTree
---
