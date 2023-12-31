#pragma once
#include <bits/stdc++.h>

template<typename T,typename U>
std::istream &operator>>(std::istream&is,std::pair<T,U>&p){is>>p.first>>p.second;return is;}
template<typename T>
std::istream &operator>>(std::istream&is,std::vector<T>&v){for(T &in:v){is>>in;}return is;}
inline void scan(int &a) { std::cin >> a; }
inline void scan(long long &a) { std::cin >> a; }
inline void scan(std::string &a) { std::cin >> a; }
inline void scan(char &a) { std::cin >> a; }
inline void scan(double &a) { std::cin >> a; }
inline void scan(long double &a) { std::cin >> a; }
template <class T, class U>
inline void scan(std::pair<T, U> &p) { std::cin >> p; }
template <class T>
inline void scan(std::vector<T> &a) { std::cin >> a; }
inline void input() {}
template <class Head, class... Tail>
inline void input(Head &head, Tail &...tail) {scan(head);input(tail...);}

template<typename T>
std::ostream &operator<<(std::ostream&os,const std::vector<T>&v){for(auto it=std::begin(v);it!=std::end(v);){os<<*it<<((++it)!=std::end(v)?" ":"");}return os;}
template<typename T>
std::ostream &operator<<(std::ostream&os,const std::set<T>&v){for(auto it=std::begin(v);it!=std::end(v);){os<<*it<<((++it)!=std::end(v)?" ":"");}return os;}
template<typename T,typename U>
std::ostream &operator<<(std::ostream&os,const std::pair<T,U>&p){os<<p.first<<" "<<p.second;return os;}
template<class T>
inline void print(const T &t){std::cout<<t<<'\n';}
template<class Head, class... Tail>
inline void print(const Head &head, const Tail &... tail){std::cout<<head<<' ';print(tail...);}
template<class... T>
inline void fin(const T &... a){print(a...);exit(0);}
template<class T>
inline void printl(const T &t){std::cout<<t<<'\n';}
template <class T>
inline void printl(const std::vector<T> &a){for(const auto &v : a) std::cout << v << '\n';}
template<class Head, class... Tail>
inline void printl(const Head &head, const Tail &... tail){std::cout<<head<<'\n';printl(tail...);}
inline void Yes(const bool b = true) { std::cout << (b ? "Yes\n" : "No\n"); }
inline void No() { std::cout << "No\n"; }
inline void YES(const bool b = true) { std::cout << (b ? "YES\n" : "NO\n"); }
inline void NO() { std::cout << "NO\n"; }

template<class T>
void trace(const T &t){std::cerr<<t<<')'<<'\n';}
template<class Head, class... Tail>
void trace(const Head &head, const Tail &... tail){std::cerr<<head<<' ';trace(tail...);}
#ifdef ONLINE_JUDGE
#define debug(...) (void(0))
#else
#define debug(...) do{std::cerr<<'('<<#__VA_ARGS__<<") = (";trace(__VA_ARGS__);}while(0)
#endif
