---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/alias.hpp
    title: template/alias.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/lazy-segment-tree.hpp
    title: LazySegmentTree
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree.hpp
    title: SegmentTree
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
  bundledCode: "#line 2 \"others/monoid.hpp\"\n#include <bits/stdc++.h>\n#line 3 \"\
    template/alias.hpp\"\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using ld = long double;\nusing vi = std::vector<int>;\nusing vvi = std::vector<vi>;\n\
    using vl = std::vector<ll>;\nusing vvl = std::vector<vl>;\nusing vd = std::vector<double>;\n\
    using vvd = std::vector<vd>;\nusing vs = std::vector<std::string>;\nusing vvs\
    \ = std::vector<vs>;\nusing vb = std::vector<bool>;\nusing vvb = std::vector<vb>;\n\
    using vc = std::vector<char>;\nusing vvc = std::vector<vc>;\nusing pii = std::pair<int,\
    \ int>;\nusing pll = std::pair<ll, ll>;\nusing mii = std::map<int, int>;\nusing\
    \ mll = std::map<ll, ll>;\ntemplate<typename T>\nstruct infinity{\n    static\
    \ constexpr T max=std::numeric_limits<T>::max();\n    static constexpr T min=std::numeric_limits<T>::min();\n\
    \    static constexpr T value=std::numeric_limits<T>::max()/2;\n    static constexpr\
    \ T mvalue=std::numeric_limits<T>::min()/2;\n};\ntemplate<typename T>constexpr\
    \ T INF=infinity<T>::value;\nconstexpr ll infl=INF<ll>;\nconstexpr int inf = INF<int>;\n\
    constexpr ld PI = 3.1415926535897932384626;\n#line 4 \"others/monoid.hpp\"\nnamespace\
    \ Monoid {\n    template<typename M,typename=void>struct has_op:std::false_type{};\n\
    \    template<typename M>struct has_op<M,decltype((void)M::op)>:std::true_type{};\n\
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
    \   return c + a * b;\n        }\n    };\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"template/alias.hpp\"\n\
    namespace Monoid {\n    template<typename M,typename=void>struct has_op:std::false_type{};\n\
    \    template<typename M>struct has_op<M,decltype((void)M::op)>:std::true_type{};\n\
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
    \   return c + a * b;\n        }\n    };\n}"
  dependsOn:
  - template/alias.hpp
  isVerificationFile: false
  path: others/monoid.hpp
  requiredBy:
  - data-structure/lazy-segment-tree.hpp
  - data-structure/segment-tree.hpp
  timestamp: '2024-01-19 15:38:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/point_add_range_sum_2.test.cpp
  - tests/aoj/DSL_2_H.test.cpp
  - tests/aoj/DSL_2_A.test.cpp
  - tests/aoj/DSL_2_F.test.cpp
  - tests/aoj/DSL_2_G.test.cpp
  - tests/aoj/DSL_2_B_2.test.cpp
  - tests/aoj/DSL_2_I.test.cpp
documentation_of: others/monoid.hpp
layout: document
redirect_from:
- /library/others/monoid.hpp
- /library/others/monoid.hpp.html
title: others/monoid.hpp
---
