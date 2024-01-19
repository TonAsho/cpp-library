#pragma once
#include <bits/stdc++.h>
#include "template/alias.hpp"
namespace Monoid {
    template<typename M,typename=void>struct has_op:std::false_type{};
    template<typename M>struct has_op<M,decltype((void)M::op)>:std::true_type{};
    template<typename M,typename=void>struct has_id:std::false_type{};
    template<typename M>struct has_id<M,decltype((void)M::id)>:std::true_type{};
    template<typename M,typename=void>struct has_inv:std::false_type{};
    template<typename M>struct has_inv<M,decltype((void)M::inv)>:std::true_type{};
    template<typename M,typename=void>struct has_get_inv:std::false_type{};
    template<typename M>struct has_get_inv<M,decltype((void)M::get_inv)>:std::true_type{};
    template<typename A,typename=void>struct has_mul_op:std::false_type{};
    template<typename A>struct has_mul_op<A,decltype((void)A::mul_op)>:std::true_type{};
    template<typename T,typename=void>struct is_semigroup:std::false_type{};
    template<typename T>struct is_semigroup<T,decltype(std::declval<typename T::value_type>(),(void)T::op)>:std::true_type{};
    template<typename T,typename=void>struct is_monoid:std::false_type{};
    template<typename T>struct is_monoid<T,decltype(std::declval<typename T::value_type>(),(void)T::op,(void)T::id)>:std::true_type{};
    template<typename T,typename=void>struct is_group:std::false_type{};
    template<typename T>struct is_group<T,decltype(std::declval<typename T::value_type>(),(void)T::op,(void)T::id,(void)T::get_inv)>:std::true_type{};
    template<typename T,typename=void>struct is_action:std::false_type{};
    template<typename T>struct is_action<T,typename std::enable_if<is_monoid<typename T::M>::value&&is_semigroup<typename T::E>::value&&(has_op<T>::value||has_mul_op<T>::value)>::type>:std::true_type{};
    template<typename T,typename=void>struct is_distributable_action:std::false_type{};
    template<typename T>struct is_distributable_action<T,typename std::enable_if<is_action<T>::value&&!has_mul_op<T>::value>::type>:std::true_type{};

    template<class T> struct Sum {
        using value_type = T;
        static constexpr T op(const T& a, const T& b) { return a + b; }
        static constexpr T id() { return T{0}; }
        static constexpr T inv(const T& a, const T& b) { return a - b; }
        static constexpr T get_inv(const T& a) { return -a; }
    };

    template<class T, T max_value = infinity<T>::max> struct Min {
        using value_type = T;
        static constexpr T op(const T& a, const T& b) { return a < b ? a : b; }
        static constexpr T id() { return max_value; }
    };

    template<class T, T min_value = infinity<T>::min> struct Max {
        using value_type = T;
        static constexpr T op(const T& a, const T& b) { return a < b ? b : a; }
        static constexpr T id() { return min_value; }
    };

    template<class T> struct Assign {
        using value_type = T;
        static constexpr T op(const T&, const T& b) { return b; }
    };

    template<class T, T max_value = infinity<T>::max> struct AssignMin {
        using M = Min<T, max_value>;
        using E = Assign<T>;
        static constexpr T op(const T& a, const T&) { return a; }
    };

    template<class T, T min_value = infinity<T>::min> struct AssignMax {
        using M = Max<T, min_value>;
        using E = Assign<T>;
        static constexpr T op(const T& a, const T&) { return a; }
    };

    template<class T> struct AssignSum {
        using M = Sum<T>;
        using E = Assign<T>;
        static constexpr T mul_op(const T& a, int b, const T&) { return a * b; }
    };

    template<class T, T max_value = infinity<T>::max> struct AddMin {
        using M = Min<T, max_value>;
        using E = Sum<T>;
        static constexpr T op(const T& a, const T& b) { return b + a; }
    };

    template<class T, T min_value = infinity<T>::min> struct AddMax {
        using M = Max<T, min_value>;
        using E = Sum<T>;
        static constexpr T op(const T& a, const T& b) { return b + a; }
    };

    template<class T> struct AddSum {
        using M = Sum<T>;
        using E = Sum<T>;
        static constexpr T mul_op(const T& a, int b, const T& c) {
            return c + a * b;
        }
    };
}