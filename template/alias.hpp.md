---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/lazy-segment-tree.hpp
    title: LazySegmentTree
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree.hpp
    title: SegmentTree
  - icon: ':warning:'
    path: math/modint.hpp
    title: ModInt
  - icon: ':heavy_check_mark:'
    path: others/monoid.hpp
    title: others/monoid.hpp
  - icon: ':warning:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':warning:'
    path: tests/joi/joi2009ho_c.cpp
    title: joi2009ho_c
  - icon: ':warning:'
    path: tests/joi/joi2011ho4.cpp
    title: joi2011ho4
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/DSL_2_A.test.cpp
    title: tests/aoj/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/aoj/DSL_2_B_2.test.cpp
    title: tests/aoj/DSL_2_B_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/aoj/DSL_2_F.test.cpp
    title: tests/aoj/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/aoj/DSL_2_G.test.cpp
    title: tests/aoj/DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/aoj/DSL_2_H.test.cpp
    title: tests/aoj/DSL_2_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/aoj/DSL_2_I.test.cpp
    title: tests/aoj/DSL_2_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/point_add_range_sum_2.test.cpp
    title: tests/yosupo/point_add_range_sum_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/alias.hpp\"\n#include <bits/stdc++.h>\n\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    using vi = std::vector<int>;\nusing vvi = std::vector<vi>;\nusing vl = std::vector<ll>;\n\
    using vvl = std::vector<vl>;\nusing vd = std::vector<double>;\nusing vvd = std::vector<vd>;\n\
    using vs = std::vector<std::string>;\nusing vvs = std::vector<vs>;\nusing vb =\
    \ std::vector<bool>;\nusing vvb = std::vector<vb>;\nusing vc = std::vector<char>;\n\
    using vvc = std::vector<vc>;\nusing pii = std::pair<int, int>;\nusing pll = std::pair<ll,\
    \ ll>;\nusing mii = std::map<int, int>;\nusing mll = std::map<ll, ll>;\ntemplate<typename\
    \ T>\nstruct infinity{\n    static constexpr T max=std::numeric_limits<T>::max();\n\
    \    static constexpr T min=std::numeric_limits<T>::min();\n    static constexpr\
    \ T value=std::numeric_limits<T>::max()/2;\n    static constexpr T mvalue=std::numeric_limits<T>::min()/2;\n\
    };\ntemplate<typename T>constexpr T INF=infinity<T>::value;\nconstexpr ll infl=INF<ll>;\n\
    constexpr int inf = INF<int>;\nconstexpr ld PI = 3.1415926535897932384626;\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n\nusing ll = long long;\nusing ull\
    \ = unsigned long long;\nusing ld = long double;\nusing vi = std::vector<int>;\n\
    using vvi = std::vector<vi>;\nusing vl = std::vector<ll>;\nusing vvl = std::vector<vl>;\n\
    using vd = std::vector<double>;\nusing vvd = std::vector<vd>;\nusing vs = std::vector<std::string>;\n\
    using vvs = std::vector<vs>;\nusing vb = std::vector<bool>;\nusing vvb = std::vector<vb>;\n\
    using vc = std::vector<char>;\nusing vvc = std::vector<vc>;\nusing pii = std::pair<int,\
    \ int>;\nusing pll = std::pair<ll, ll>;\nusing mii = std::map<int, int>;\nusing\
    \ mll = std::map<ll, ll>;\ntemplate<typename T>\nstruct infinity{\n    static\
    \ constexpr T max=std::numeric_limits<T>::max();\n    static constexpr T min=std::numeric_limits<T>::min();\n\
    \    static constexpr T value=std::numeric_limits<T>::max()/2;\n    static constexpr\
    \ T mvalue=std::numeric_limits<T>::min()/2;\n};\ntemplate<typename T>constexpr\
    \ T INF=infinity<T>::value;\nconstexpr ll infl=INF<ll>;\nconstexpr int inf = INF<int>;\n\
    constexpr ld PI = 3.1415926535897932384626;"
  dependsOn: []
  isVerificationFile: false
  path: template/alias.hpp
  requiredBy:
  - data-structure/lazy-segment-tree.hpp
  - data-structure/segment-tree.hpp
  - math/modint.hpp
  - template/template.hpp
  - others/monoid.hpp
  - tests/joi/joi2009ho_c.cpp
  - tests/joi/joi2011ho4.cpp
  timestamp: '2023-12-17 11:32:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/point_add_range_sum_2.test.cpp
  - tests/aoj/DSL_2_H.test.cpp
  - tests/aoj/DSL_2_A.test.cpp
  - tests/aoj/DSL_2_F.test.cpp
  - tests/aoj/DSL_2_G.test.cpp
  - tests/aoj/DSL_2_B_2.test.cpp
  - tests/aoj/DSL_2_I.test.cpp
documentation_of: template/alias.hpp
layout: document
redirect_from:
- /library/template/alias.hpp
- /library/template/alias.hpp.html
title: template/alias.hpp
---
