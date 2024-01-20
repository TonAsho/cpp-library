---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/lazy-segment-tree.hpp
    title: LazySegmentTree
  - icon: ':heavy_check_mark:'
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_F
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_F
  bundledCode: "#line 1 \"tests/aoj/DSL_2_F.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_F\"\
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
    \   return c + a * b;\n        }\n    };\n}\n#line 4 \"data-structure/lazy-segment-tree.hpp\"\
    \n/**\n * @brief LazySegmentTree\n**/\ntemplate<class A> \nstruct LazySegmentTree\
    \ {\n    static_assert(Monoid::is_action<A>::value, \"A must be action\");\n \
    \ private:\n    using M = typename A::M;\n    using E = typename A::E;\n    using\
    \ T = typename M::value_type;\n    using U = typename E::value_type;\n    int\
    \ h, n, ori;\n    std::vector<T> data;\n    std::vector<U> lazy;\n    std::vector<bool>\
    \ lazyflag;\n\n    template<bool AlwaysTrue = true, typename std::enable_if<!Monoid::has_mul_op<A>::value\
    \ && AlwaysTrue>::type* = nullptr>\n    static inline T Aop(const U& a, const\
    \ T& b, int) {\n        return A::op(a, b);\n    }\n    template<bool AlwaysTrue\
    \ = true, typename std::enable_if<Monoid::has_mul_op<A>::value && AlwaysTrue>::type*\
    \ = nullptr>\n    static inline T Aop(const U& a, const T& b, int c) {\n     \
    \   return A::mul_op(a, c, b);\n    }\n    void all_apply(int k, const U& x, int\
    \ d) {\n        data[k] = Aop(x, data[k], d);\n        if (k < n) {\n        \
    \    if (lazyflag[k]) {\n                lazy[k] = E::op(lazy[k], x);\n      \
    \      }\n            else {\n                lazy[k] = x;\n                lazyflag[k]\
    \ = true;\n            }\n        }\n    }\n    void eval(int k, int d) {\n  \
    \      if (lazyflag[k]) {\n            all_apply(k << 1, lazy[k], d >> 1);\n \
    \           all_apply(k << 1 ^ 1, lazy[k], d >> 1);\n            lazyflag[k] =\
    \ false;\n        }\n    }\n    void calc(int k) { data[k] = M::op(data[k << 1],\
    \ data[k << 1 ^ 1]); }\n  public:\n    LazySegmentTree() : LazySegmentTree(0)\
    \ {}\n    LazySegmentTree(int n) : LazySegmentTree(std::vector<T>(n, M::id()))\
    \ {}\n    LazySegmentTree(int n, const T& v) : LazySegmentTree(std::vector<T>(n,\
    \ v)) {}\n    LazySegmentTree(const std::vector<T>& v) { init(v); }\n    void\
    \ init(const std::vector<T>& v) {\n        ori = v.size();\n        h = 0;\n \
    \       while((1 << h) < ori) h++;\n        n = 1 << h;\n        data.assign(n\
    \ << 1, M::id());\n        for(int i = 0; i < ori; i++) data[n + i] = v[i];\n\
    \        for(int i = n - 1; i > 0; i--) calc(i);\n        lazy.resize(n);\n  \
    \      lazyflag.assign(n, false);\n    }\n    T prod(int l, int r) {\n       \
    \ assert(0 <= l && l <= r && r <= ori);\n        if (l == r) return M::id();\n\
    \        l += n, r += n;\n        for(int i = h; i > 0; i--) {\n            bool\
    \ seen = false;\n            if (((l >> i) << i) != l) eval(l >> i, 1 << i), seen\
    \ = true;\n            if (((r >> i) << i) != r) eval((r - 1) >> i, 1 << i), seen\
    \ = true;\n            if (!seen) break;\n        }\n        T lsm = M::id(),\
    \ rsm = M::id();\n        while (l != r) {\n            if (l & 1) lsm = M::op(lsm,\
    \ data[l++]);\n            if (r & 1) rsm = M::op(data[--r], rsm);\n         \
    \   l >>= 1, r >>= 1;\n        }\n        return M::op(lsm, rsm);\n    }\n   \
    \ T get(int k) {\n        assert(0 <= k && k < ori);\n        k += n;\n      \
    \  for(int i = h; i > 0; i--) eval(k >> i, 1 << i);\n        return data[k];\n\
    \    }\n    T operator[](int k) { return get(k); }\n    T all_prod() const { return\
    \ data[1]; }\n    template<class Upd> void update(int k, const Upd& upd) {\n \
    \       assert(0 <= k && k < ori);\n        k += n;\n        for(int i = h; i\
    \ > 0; i--) eval(k >> i, 1 << i);\n        data[k] = upd(data[k]);\n        for(int\
    \ i = 1; i <= h; i++) calc(k >> i);\n    }\n    void set(int k, const T& x) {\n\
    \        update(k, [&](const T&) -> T { return x; });\n    }\n    void apply(int\
    \ k, const U& x) {\n        update(k, [&](const T& a) -> T { return A::op(x, a);\
    \ });\n    }\n    void apply(int l, int r, const U& x) {\n        assert(0 <=\
    \ l && l <= r && r <= ori);\n        if (l == r) return;\n        l += n, r +=\
    \ n;\n        int lst = h + 1;\n        for(int i = h; i > 0; i--) {\n       \
    \     if (((l >> i) << i) != l) eval(l >> i, 1 << i), lst = i;\n            if\
    \ (((r >> i) << i) != r) eval((r - 1) >> i, 1 << i), lst = i;\n            if\
    \ (lst != i) break;\n        }\n        for (int l2 = l, r2 = r, d = 1; l2 !=\
    \ r2; l2 >>= 1, r2 >>= 1, d <<= 1) {\n            if (l2 & 1) all_apply(l2++,\
    \ x, d);\n            if (r2 & 1) all_apply(--r2, x, d);\n        }\n        for(int\
    \ i = lst; i <= h; i++) {\n            if (((l >> i) << i) != l) calc(l >> i);\n\
    \            if (((r >> i) << i) != r) calc((r - 1) >> i);\n        }\n    }\n\
    \    template<class C> int max_right(int l, const C& cond) {\n        assert(0\
    \ <= l && l <= ori);\n        assert(cond(M::id()));\n        if (l == ori) return\
    \ ori;\n        l += n;\n        for(int i = h; i > 0; i--) {\n            if\
    \ (((l >> i) << i) != l) eval(l >> i, 1 << i);\n            else break;\n    \
    \    }\n        T sm = M::id();\n        int d = 1;\n        do {\n          \
    \  while ((l & 1) == 0) l >>= 1, d <<= 1;\n            if (!cond(M::op(sm, data[l])))\
    \ {\n                while (l < n) {\n                    eval(l, d);\n      \
    \              l <<= 1;\n                    d >>= 1;\n                    if\
    \ (cond(M::op(sm, data[l]))) sm = M::op(sm, data[l++]);\n                }\n \
    \               return l - n;\n            }\n            sm = M::op(sm, data[l++]);\n\
    \        } while ((l & -l) != l);\n        return ori;\n    }\n    template<class\
    \ C> int min_left(int r, const C& cond) {\n        assert(0 <= r && r <= ori);\n\
    \        assert(cond(M::id()));\n        if (r == 0) return 0;\n        r += n;\n\
    \        for(int i = h; i > 0; i--) {\n            if (((r >> i) << i) != r) eval((r\
    \ - 1) >> i, 1 << i);\n            else break;\n        }\n        T sm = M::id();\n\
    \        int d = 1;\n        do {\n            --r;\n            while ((r & 1)\
    \ && r > 1) r >>= 1, d <<= 1;\n            if (!cond(M::op(data[r], sm))) {\n\
    \                while (r < n) {\n                    eval(r, d);\n          \
    \          r = r << 1 ^ 1;\n                    d >>= 1;\n                   \
    \ if (cond(M::op(data[r], sm))) sm = M::op(data[r--], sm);\n                }\n\
    \                return r + 1 - n;\n            }\n            sm = M::op(data[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n};\n#line\
    \ 4 \"tests/aoj/DSL_2_F.test.cpp\"\n\nint main(){\n    int N,Q;\n    std::cin>>N>>Q;\n\
    \    LazySegmentTree<Monoid::AssignMin<ll>> RMQ(N,(1ll<<31)-1);\n    while(Q--){\n\
    \        int op,x,y,val;\n        std::cin>>op>>x>>y;\n        if(op==0){\n  \
    \          std::cin>>val;\n            RMQ.apply(x,y+1,val);\n        }else{\n\
    \            std::cout<<RMQ.prod(x,y+1)<<std::endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_F\"\n#include\
    \ <bits/stdc++.h>\n#include \"data-structure/lazy-segment-tree.hpp\"\n\nint main(){\n\
    \    int N,Q;\n    std::cin>>N>>Q;\n    LazySegmentTree<Monoid::AssignMin<ll>>\
    \ RMQ(N,(1ll<<31)-1);\n    while(Q--){\n        int op,x,y,val;\n        std::cin>>op>>x>>y;\n\
    \        if(op==0){\n            std::cin>>val;\n            RMQ.apply(x,y+1,val);\n\
    \        }else{\n            std::cout<<RMQ.prod(x,y+1)<<std::endl;\n        }\n\
    \    }\n}"
  dependsOn:
  - data-structure/lazy-segment-tree.hpp
  - others/monoid.hpp
  - template/alias.hpp
  isVerificationFile: true
  path: tests/aoj/DSL_2_F.test.cpp
  requiredBy: []
  timestamp: '2024-01-19 17:51:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/DSL_2_F.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/DSL_2_F.test.cpp
- /verify/tests/aoj/DSL_2_F.test.cpp.html
title: tests/aoj/DSL_2_F.test.cpp
---
