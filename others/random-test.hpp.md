---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"others/random-test.hpp\"\n#include <bits/stdc++.h>\nstruct\
    \ RandomTest {\n  private:\n    std::random_device rd;\n    std::mt19937 mt;\n\
    \  public:\n    RandomTest() { mt.seed(rd()); }\n    long long get_int(long long\
    \ mn, long long mx) {\n        mx++;\n        int res = mt() % mx;\n        while(res\
    \ < mn) res = mt() % mx;\n        return res;\n    }\n    template<typename T>\n\
    \    std::vector<T> get_vec(long long mn, long long mx, int size) {\n        std::vector<T>\
    \ res(size);\n        for(int i = 0; i < size; i++) res[i] = get_int(mn, mx);\n\
    \        return res;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nstruct RandomTest {\n  private:\n    std::random_device\
    \ rd;\n    std::mt19937 mt;\n  public:\n    RandomTest() { mt.seed(rd()); }\n\
    \    long long get_int(long long mn, long long mx) {\n        mx++;\n        int\
    \ res = mt() % mx;\n        while(res < mn) res = mt() % mx;\n        return res;\n\
    \    }\n    template<typename T>\n    std::vector<T> get_vec(long long mn, long\
    \ long mx, int size) {\n        std::vector<T> res(size);\n        for(int i =\
    \ 0; i < size; i++) res[i] = get_int(mn, mx);\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: others/random-test.hpp
  requiredBy: []
  timestamp: '2023-12-18 16:56:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/random-test.hpp
layout: document
redirect_from:
- /library/others/random-test.hpp
- /library/others/random-test.hpp.html
title: others/random-test.hpp
---
