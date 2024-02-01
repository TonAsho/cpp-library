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
  - icon: ':warning:'
    path: tests/joi/joi2011ho4.cpp
    title: joi2011ho4
  - icon: ':warning:'
    path: tests/joi/joi2015yo_e.cpp
    title: joi2015yo_e
  - icon: ':warning:'
    path: tests/joi/joi2020ho_a.cpp
    title: joi2020ho_a
  - icon: ':warning:'
    path: tests/joi/joi2020ho_b.cpp
    title: joi2020ho_b
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/func.hpp\"\n#include <bits/stdc++.h>\n\ntemplate<class...\
    \ T>\nconstexpr auto max(T... a){ return max(std::initializer_list<common_type_t<T...>>{a...});\
    \ }\ntemplate<class... T>\nconstexpr auto min(T... a){ return min(std::initializer_list<common_type_t<T...>>{a...});\
    \ }\ntemplate<typename T, typename U> bool chmin(T &a, U b) {if (a>b) {a=b;return\
    \ true;}return false;}\ntemplate<typename T, typename U> bool chmax(T &a, U b)\
    \ {if (a<b) {a=b;return true;}return false;}\ntemplate<class T>\nstd::vector<std::vector<T>>\
    \ ROTATE(std::vector<std::vector<T>> X) {\n    if(X.size() == 0) return X;\n \
    \   std::vector<vector<T>> res(X[0].size(),std::vector<T>(X.size()));\n    rep(i,X.size())rep(j,X[0].size())res[j][X.size()-i-1]=X[i][j];\n\
    \    return res;\n}\ntemplate<typename T>\nstruct CumulativeSum {\n  private:\
    \    \n    std::vector<T> data;\n    bool sorted = false;\n  public:\n    CumulativeSum(int\
    \ n) : data(n + 1, 0) {}\n    CumulativeSum(const std::vector<T> &v) : data(v.size()\
    \ + 1, 0) {\n        for(int i = 0; i < (int)v.size(); i++) add(i, v[i]);\n  \
    \  }\n    void add(int k, const T &val) { data[k + 1] += val; }\n    void build()\
    \ {\n        assert(!sorted); sorted = true;\n        for(int i = 1; i < (int)data.size();\
    \ i++) data[i] += data[i - 1];\n    }\n    T prod(int r) {\n        assert(sorted);\n\
    \        return (r < 0 ? 0 : data[min(r, (int)data.size() - 1)]);\n    }\n   \
    \ T prod(int l, int r) {\n        assert(sorted);\n        return prod(r) - prod(l);\
    \ \n    }\n};\ninline constexpr int popcnt(ull x){\n#if __cplusplus>=202002L\n\
    \  return std::popcount(x);\n#endif\n    x=(x&0x5555555555555555)+((x>>1)&0x5555555555555555);\n\
    \    x=(x&0x3333333333333333)+((x>>2)&0x3333333333333333);\n    x=(x&0x0f0f0f0f0f0f0f0f)+((x>>4)&0x0f0f0f0f0f0f0f0f);\n\
    \    x=(x&0x00ff00ff00ff00ff)+((x>>8)&0x00ff00ff00ff00ff);\n    x=(x&0x0000ffff0000ffff)+((x>>16)&0x0000ffff0000ffff);\n\
    \    return (x&0x00000000ffffffff)+((x>>32)&0x00000000ffffffff);\n}\ninline constexpr\
    \ bool is_prime(ll n){\n    if(n<=1)return false;\n    for(ll i=2;i*i<=n;i++){\n\
    \        if(n%i==0)return false;\n    }\n    return true;\n}\ninline constexpr\
    \ ll my_pow(ll a,ll b){\n    ll res=1;\n    while(b){\n        if(b&1)res*=a;\n\
    \        a*=a;\n        b>>=1;\n    }\n    return res;\n}\ninline constexpr ll\
    \ mod_pow(ll a, ll b, const ll &mod){\n    if(mod==1)return 0;\n    a%=mod;\n\
    \    ll res=1;\n    while(b){\n        if(b&1)(res*=a)%=mod;\n        (a*=a)%=mod;\n\
    \        b>>=1;\n    }\n    return res;\n}\ninline ll mod_inv(ll a, const ll &mod){\n\
    \    ll b=mod,x=1,u=0,t;\n    while(b){\n        t=a/b;\n        std::swap(a-=t*b,b);\n\
    \        std::swap(x-=t*u,u);\n    }\n    if(x<0)x+=mod;\n    return x;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n\ntemplate<class... T>\nconstexpr\
    \ auto max(T... a){ return max(std::initializer_list<common_type_t<T...>>{a...});\
    \ }\ntemplate<class... T>\nconstexpr auto min(T... a){ return min(std::initializer_list<common_type_t<T...>>{a...});\
    \ }\ntemplate<typename T, typename U> bool chmin(T &a, U b) {if (a>b) {a=b;return\
    \ true;}return false;}\ntemplate<typename T, typename U> bool chmax(T &a, U b)\
    \ {if (a<b) {a=b;return true;}return false;}\ntemplate<class T>\nstd::vector<std::vector<T>>\
    \ ROTATE(std::vector<std::vector<T>> X) {\n    if(X.size() == 0) return X;\n \
    \   std::vector<vector<T>> res(X[0].size(),std::vector<T>(X.size()));\n    rep(i,X.size())rep(j,X[0].size())res[j][X.size()-i-1]=X[i][j];\n\
    \    return res;\n}\ntemplate<typename T>\nstruct CumulativeSum {\n  private:\
    \    \n    std::vector<T> data;\n    bool sorted = false;\n  public:\n    CumulativeSum(int\
    \ n) : data(n + 1, 0) {}\n    CumulativeSum(const std::vector<T> &v) : data(v.size()\
    \ + 1, 0) {\n        for(int i = 0; i < (int)v.size(); i++) add(i, v[i]);\n  \
    \  }\n    void add(int k, const T &val) { data[k + 1] += val; }\n    void build()\
    \ {\n        assert(!sorted); sorted = true;\n        for(int i = 1; i < (int)data.size();\
    \ i++) data[i] += data[i - 1];\n    }\n    T prod(int r) {\n        assert(sorted);\n\
    \        return (r < 0 ? 0 : data[min(r, (int)data.size() - 1)]);\n    }\n   \
    \ T prod(int l, int r) {\n        assert(sorted);\n        return prod(r) - prod(l);\
    \ \n    }\n};\ninline constexpr int popcnt(ull x){\n#if __cplusplus>=202002L\n\
    \  return std::popcount(x);\n#endif\n    x=(x&0x5555555555555555)+((x>>1)&0x5555555555555555);\n\
    \    x=(x&0x3333333333333333)+((x>>2)&0x3333333333333333);\n    x=(x&0x0f0f0f0f0f0f0f0f)+((x>>4)&0x0f0f0f0f0f0f0f0f);\n\
    \    x=(x&0x00ff00ff00ff00ff)+((x>>8)&0x00ff00ff00ff00ff);\n    x=(x&0x0000ffff0000ffff)+((x>>16)&0x0000ffff0000ffff);\n\
    \    return (x&0x00000000ffffffff)+((x>>32)&0x00000000ffffffff);\n}\ninline constexpr\
    \ bool is_prime(ll n){\n    if(n<=1)return false;\n    for(ll i=2;i*i<=n;i++){\n\
    \        if(n%i==0)return false;\n    }\n    return true;\n}\ninline constexpr\
    \ ll my_pow(ll a,ll b){\n    ll res=1;\n    while(b){\n        if(b&1)res*=a;\n\
    \        a*=a;\n        b>>=1;\n    }\n    return res;\n}\ninline constexpr ll\
    \ mod_pow(ll a, ll b, const ll &mod){\n    if(mod==1)return 0;\n    a%=mod;\n\
    \    ll res=1;\n    while(b){\n        if(b&1)(res*=a)%=mod;\n        (a*=a)%=mod;\n\
    \        b>>=1;\n    }\n    return res;\n}\ninline ll mod_inv(ll a, const ll &mod){\n\
    \    ll b=mod,x=1,u=0,t;\n    while(b){\n        t=a/b;\n        std::swap(a-=t*b,b);\n\
    \        std::swap(x-=t*u,u);\n    }\n    if(x<0)x+=mod;\n    return x;\n}"
  dependsOn: []
  isVerificationFile: false
  path: template/func.hpp
  requiredBy:
  - template/template.hpp
  - tests/joi/joi2011ho4.cpp
  - tests/joi/joi2020ho_b.cpp
  - tests/joi/joi2009ho_c.cpp
  - tests/joi/joi2015yo_e.cpp
  - tests/joi/joi2020ho_a.cpp
  timestamp: '2023-12-17 11:32:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/func.hpp
layout: document
redirect_from:
- /library/template/func.hpp
- /library/template/func.hpp.html
title: template/func.hpp
---
