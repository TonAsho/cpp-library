---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':warning:'
    path: tests/joi/joi2009ho_c.cpp
    title: joi2009ho_c
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 2 "template/macro.hpp"

    #include <bits/stdc++.h>


    #define SELECT4(a,b,c,d,e,...) e

    #define SELECT3(a,b,c,d,...) d

    #define REP1(a) for(ll i = 0; i < (ll)(a); ++i)

    #define REP2(i, a) for(ll i = 0; i < (ll)(a); ++i)

    #define REP3(i, a, b) for(ll i = (ll)(a); i < (ll)(b); ++i)

    #define REP4(i, a, b, c) for(ll i = (ll)(a); i < (ll)(b); i += (ll)(c))

    #define rep(...) SELECT4(__VA_ARGS__,REP4,REP3,REP2,REP1)(__VA_ARGS__)

    #define RREP1(a) for (ll i = (ll)(a)-1; i >= 0; --i)

    #define RREP2(i, a) for (ll i = (ll)(a)-1; i >=0; --i)

    #define RREP3(i, a, b) for (ll i = (ll)(a)-1; i >= (ll)(b); --i)

    #define rrep(...) SELECT3(__VA_ARGS__,RREP3,RREP2,RREP1)(__VA_ARGS__)

    #define all(x) (x).begin(),(x).end()

    #define rall(x) (x).rbegin(),(x).rend()

    #define SUM(a) accumulate(all(a),0LL)

    #define MIN(a) *min_element(all(a))

    #define MAX(a) *max_element(all(a))

    #define INT(...) int __VA_ARGS__;input(__VA_ARGS__)

    #define LL(...) ll __VA_ARGS__;input(__VA_ARGS__)

    #define STR(...) string __VA_ARGS__;input(__VA_ARGS__)

    #define CHR(...) char __VA_ARGS__;input(__VA_ARGS__)

    #define DBL(...) double __VA_ARGS__;input(__VA_ARGS__)

    #define LD(...) ld __VA_ARGS__;input(__VA_ARGS__)

    #define pb push_back

    #define eb emplace_back

    '
  code: '#pragma once

    #include <bits/stdc++.h>


    #define SELECT4(a,b,c,d,e,...) e

    #define SELECT3(a,b,c,d,...) d

    #define REP1(a) for(ll i = 0; i < (ll)(a); ++i)

    #define REP2(i, a) for(ll i = 0; i < (ll)(a); ++i)

    #define REP3(i, a, b) for(ll i = (ll)(a); i < (ll)(b); ++i)

    #define REP4(i, a, b, c) for(ll i = (ll)(a); i < (ll)(b); i += (ll)(c))

    #define rep(...) SELECT4(__VA_ARGS__,REP4,REP3,REP2,REP1)(__VA_ARGS__)

    #define RREP1(a) for (ll i = (ll)(a)-1; i >= 0; --i)

    #define RREP2(i, a) for (ll i = (ll)(a)-1; i >=0; --i)

    #define RREP3(i, a, b) for (ll i = (ll)(a)-1; i >= (ll)(b); --i)

    #define rrep(...) SELECT3(__VA_ARGS__,RREP3,RREP2,RREP1)(__VA_ARGS__)

    #define all(x) (x).begin(),(x).end()

    #define rall(x) (x).rbegin(),(x).rend()

    #define SUM(a) accumulate(all(a),0LL)

    #define MIN(a) *min_element(all(a))

    #define MAX(a) *max_element(all(a))

    #define INT(...) int __VA_ARGS__;input(__VA_ARGS__)

    #define LL(...) ll __VA_ARGS__;input(__VA_ARGS__)

    #define STR(...) string __VA_ARGS__;input(__VA_ARGS__)

    #define CHR(...) char __VA_ARGS__;input(__VA_ARGS__)

    #define DBL(...) double __VA_ARGS__;input(__VA_ARGS__)

    #define LD(...) ld __VA_ARGS__;input(__VA_ARGS__)

    #define pb push_back

    #define eb emplace_back'
  dependsOn: []
  isVerificationFile: false
  path: template/macro.hpp
  requiredBy:
  - template/template.hpp
  - tests/joi/joi2009ho_c.cpp
  timestamp: '2023-12-17 11:32:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/macro.hpp
layout: document
redirect_from:
- /library/template/macro.hpp
- /library/template/macro.hpp.html
title: template/macro.hpp
---
