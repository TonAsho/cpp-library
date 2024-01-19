---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree.hpp
    title: SegmentTree
  - icon: ':question:'
    path: others/monoid.hpp
    title: others/monoid.hpp
  - icon: ':question:'
    path: template/alias.hpp
    title: template/alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"tests/aoj/DSL_2_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n#include <bits/stdc++.h>\n#line 3 \"template/alias.hpp\"\n\nusing ll = long\
    \ long;\nusing ull = unsigned long long;\nusing ld = long double;\nusing vi =\
    \ std::vector<int>;\nusing vvi = std::vector<vi>;\nusing vl = std::vector<ll>;\n\
    using vvl = std::vector<vl>;\nusing vd = std::vector<double>;\nusing vvd = std::vector<vd>;\n\
    using vs = std::vector<std::string>;\nusing vvs = std::vector<vs>;\nusing vb =\
    \ std::vector<bool>;\nusing vvb = std::vector<vb>;\nusing vc = std::vector<char>;\n\
    using vvc = std::vector<vc>;\nusing pii = std::pair<int, int>;\nusing pll = std::pair<ll,\
    \ ll>;\nusing mii = std::map<int, int>;\nusing mll = std::map<ll, ll>;\ntemplate<typename\
    \ T>\nstruct infinity{\n    static constexpr T max=std::numeric_limits<T>::max();\n\
    \    static constexpr T min=std::numeric_limits<T>::min();\n    static constexpr\
    \ T value=std::numeric_limits<T>::max()/2;\n    static constexpr T mvalue=std::numeric_limits<T>::min()/2;\n\
    };\ntemplate<typename T>constexpr T INF=infinity<T>::value;\nconstexpr ll infl=INF<ll>;\n\
    constexpr int inf = INF<int>;\nconstexpr ld PI = 3.1415926535897932384626;\n#line\
    \ 4 \"others/monoid.hpp\"\nnamespace Monoid {\n    template<typename M,typename=void>struct\
    \ has_op:std::false_type{};\n    template<typename M>struct has_op<M,decltype((void)M::op)>:std::true_type{};\n\
    \    template<typename M,typename=void>struct has_id:std::false_type{};\n    template<typename\
    \ M>struct has_id<M,decltype((void)M::id)>:std::true_type{};\n    template<typename\
    \ M,typename=void>struct has_inv:std::false_type{};\n    template<typename M>struct\
    \ has_inv<M,decltype((void)M::inv)>:std::true_type{};\n    template<typename M,typename=void>struct\
    \ has_get_inv:std::false_type{};\n    template<typename M>struct has_get_inv<M,decltype((void)M::get_inv)>:std::true_type{};\n\
    \    template<typename A,typename=void>struct has_mul_op:std::false_type{};\n\
    \    template<typename A>struct has_mul_op<A,decltype((void)A::mul_op)>:std::true_type{};\n\
    \    template<typename T,typename=void>struct is_semigroup:std::false_type{};\n\
    \    template<typename T>struct is_semigroup<T,decltype(std::declval<typename\
    \ T::value_type>(),(void)T::op)>:std::true_type{};\n    template<typename T,typename=void>struct\
    \ is_monoid:std::false_type{};\n    template<typename T>struct is_monoid<T,decltype(std::declval<typename\
    \ T::value_type>(),(void)T::op,(void)T::id)>:std::true_type{};\n    template<typename\
    \ T,typename=void>struct is_group:std::false_type{};\n    template<typename T>struct\
    \ is_group<T,decltype(std::declval<typename T::value_type>(),(void)T::op,(void)T::id,(void)T::get_inv)>:std::true_type{};\n\
    \    template<typename T,typename=void>struct is_action:std::false_type{};\n \
    \   template<typename T>struct is_action<T,typename std::enable_if<is_monoid<typename\
    \ T::M>::value&&is_semigroup<typename T::E>::value&&(has_op<T>::value||has_mul_op<T>::value)>::type>:std::true_type{};\n\
    \    template<typename T,typename=void>struct is_distributable_action:std::false_type{};\n\
    \    template<typename T>struct is_distributable_action<T,typename std::enable_if<is_action<T>::value&&!has_mul_op<T>::value>::type>:std::true_type{};\n\
    \n    template<class T> struct Sum {\n        using value_type = T;\n        static\
    \ constexpr T op(const T& a, const T& b) { return a + b; }\n        static constexpr\
    \ T id() { return T{0}; }\n        static constexpr T inv(const T& a, const T&\
    \ b) { return a - b; }\n        static constexpr T get_inv(const T& a) { return\
    \ -a; }\n    };\n\n    template<class T, T max_value = infinity<T>::max> struct\
    \ Min {\n        using value_type = T;\n        static constexpr T op(const T&\
    \ a, const T& b) { return a < b ? a : b; }\n        static constexpr T id() {\
    \ return max_value; }\n    };\n\n    template<class T, T min_value = infinity<T>::min>\
    \ struct Max {\n        using value_type = T;\n        static constexpr T op(const\
    \ T& a, const T& b) { return a < b ? b : a; }\n        static constexpr T id()\
    \ { return min_value; }\n    };\n\n    template<class T> struct Assign {\n   \
    \     using value_type = T;\n        static constexpr T op(const T&, const T&\
    \ b) { return b; }\n    };\n\n    template<class T, T max_value = infinity<T>::max>\
    \ struct AssignMin {\n        using M = Min<T, max_value>;\n        using E =\
    \ Assign<T>;\n        static constexpr T op(const T& a, const T&) { return a;\
    \ }\n    };\n\n    template<class T, T min_value = infinity<T>::min> struct AssignMax\
    \ {\n        using M = Max<T, min_value>;\n        using E = Assign<T>;\n    \
    \    static constexpr T op(const T& a, const T&) { return a; }\n    };\n\n   \
    \ template<class T> struct AssignSum {\n        using M = Sum<T>;\n        using\
    \ E = Assign<T>;\n        static constexpr T mul_op(const T& a, int b, const T&)\
    \ { return a * b; }\n    };\n\n    template<class T, T max_value = infinity<T>::max>\
    \ struct AddMin {\n        using M = Min<T, max_value>;\n        using E = Sum<T>;\n\
    \        static constexpr T op(const T& a, const T& b) { return b + a; }\n   \
    \ };\n\n    template<class T, T min_value = infinity<T>::min> struct AddMax {\n\
    \        using M = Max<T, min_value>;\n        using E = Sum<T>;\n        static\
    \ constexpr T op(const T& a, const T& b) { return b + a; }\n    };\n\n    template<class\
    \ T> struct AddSum {\n        using M = Sum<T>;\n        using E = Sum<T>;\n \
    \       static constexpr T mul_op(const T& a, int b, const T& c) {\n         \
    \   return c + a * b;\n        }\n    };\n}\n#line 4 \"data-structure/segment-tree.hpp\"\
    \n/**\n * @brief SegmentTree\n**/\ntemplate<class M>\nstruct SegmentTree {\n \
    \ private:\n    using T = typename M::value_type;\n    int n, sz;\n    std::vector<T>\
    \ data;\n  public:\n    SegmentTree() : SegmentTree(0) {}\n    SegmentTree(int\
    \ n, const T &e = M::id()) : SegmentTree(std::vector<T>(n, e)) {}\n    SegmentTree(const\
    \ std::vector<T> &v) : n(v.size()), sz(1) {\n        while(sz < n) sz <<= 1;\n\
    \        data.resize(sz << 1, M::id());\n        for(int i = 0; i < n; ++i) data[sz\
    \ + i] = v[i];\n        for(int i = sz - 1; i >= 1; i--) data[i] = M::op(data[i\
    \ << 1], data[i << 1 ^ 1]);\n    }\n    template<class Upd>\n    void update(int\
    \ k,const Upd &upd){\n        k += sz;\n        data[k] = upd(data[k]);\n    \
    \    while(k >>= 1) data[k] = M::op(data[k << 1], data[k << 1^1]);\n    }\n  \
    \  void set(int k,const T &x){\n        update(k, [&](T) -> T { return x; });\n\
    \    }\n    void apply(int k,const T &x){\n        update(k, [&](T y) -> T { return\
    \ M::op(y, x); });\n    }\n    T prod(int l, int r) const {\n        l += sz,\
    \ r += sz;\n        T lsm = M::id(), rsm = M::id();\n        while(l != r) {\n\
    \            if(l & 1) lsm = M::op(lsm, data[l++]);\n            if(r & 1) rsm\
    \ = M::op(data[--r], rsm);\n            l >>= 1;\n            r >>= 1;\n     \
    \   }\n        return M::op(lsm, rsm);\n    }\n    T all_prod() const { return\
    \ data[1]; }\n    T get(int x) const { return data[sz + x]; }\n    T operator[](int\
    \ x) const { return get(x); }\n    template<class F>\n    int max_right(int l,\
    \ const F &f) const {\n        if(l == n) return n;\n        l += sz;\n      \
    \  T sum = M::id();\n        do {\n            while((l & 1) == 0) l >>= 1;\n\
    \            if(!f(M::op(sum, data[l]))) {\n                while(l < sz) {\n\
    \                    l <<= 1;\n                    if(f(M::op(sum, data[l])))\
    \ sum = M::op(sum, data[l++]);\n                }\n                return l-sz;\n\
    \            }\n            sum = M::op(sum, data[l++]);\n        } while((l &\
    \ -l) != l);\n        return n;\n    }\n    template<class F>\n    int min_left(int\
    \ r, const F &f) const {\n        if(r == 0) return 0;\n        r += sz;\n   \
    \     T sum = M::id();\n        do{\n            --r;\n            while((r &\
    \ 1) && r > 1) r >>= 1;\n            if(!f(M::op(data[r],sum))) {\n          \
    \      while(r < sz) {\n                    r = (r << 1) ^ 1;\n              \
    \      if(f(M::op(data[r],sum))) sum = M::op(data[r--], sum);\n              \
    \  }\n                return r + 1 - sz;\n            }\n            sum = M::op(data[r],\
    \ sum);\n        } while((r & -r) != r);\n        return 0;\n    }\n};\n#line\
    \ 4 \"tests/aoj/DSL_2_A.test.cpp\"\n\nint main(){\n    int N,Q;\n    std::cin>>N>>Q;\n\
    \    SegmentTree<Monoid::Min<ll,(1ll<<31)-1>> RMQ(N);\n    while(Q--){\n     \
    \   int op,x,y;\n        std::cin>>op>>x>>y;\n        if(op==1)std::cout<<RMQ.prod(x,y+1)<<std::endl;\n\
    \        else RMQ.set(x,y); }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n#include <bits/stdc++.h>\n#include \"data-structure/segment-tree.hpp\"\n\nint\
    \ main(){\n    int N,Q;\n    std::cin>>N>>Q;\n    SegmentTree<Monoid::Min<ll,(1ll<<31)-1>>\
    \ RMQ(N);\n    while(Q--){\n        int op,x,y;\n        std::cin>>op>>x>>y;\n\
    \        if(op==1)std::cout<<RMQ.prod(x,y+1)<<std::endl;\n        else RMQ.set(x,y);\
    \ }\n}"
  dependsOn:
  - data-structure/segment-tree.hpp
  - others/monoid.hpp
  - template/alias.hpp
  isVerificationFile: true
  path: tests/aoj/DSL_2_A.test.cpp
  requiredBy: []
  timestamp: '2024-01-19 15:38:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/DSL_2_A.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/DSL_2_A.test.cpp
- /verify/tests/aoj/DSL_2_A.test.cpp.html
title: tests/aoj/DSL_2_A.test.cpp
---
