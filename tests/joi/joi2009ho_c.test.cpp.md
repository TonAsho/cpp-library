---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':x:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':x:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':x:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':x:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/joi2009ho/tasks/joi2009ho_c
    links:
    - https://atcoder.jp/contests/joi2009ho/tasks/joi2009ho_c
  bundledCode: "#line 1 \"tests/joi/joi2009ho_c.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/joi2009ho/tasks/joi2009ho_c\"\
    \n#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nvoid _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main();\
    \ return 0;}\n#line 3 \"template/macro.hpp\"\n\n#define SELECT4(a,b,c,d,e,...)\
    \ e\n#define SELECT3(a,b,c,d,...) d\n#define REP1(a) for(ll i = 0; i < (ll)(a);\
    \ ++i)\n#define REP2(i, a) for(ll i = 0; i < (ll)(a); ++i)\n#define REP3(i, a,\
    \ b) for(ll i = (ll)(a); i < (ll)(b); ++i)\n#define REP4(i, a, b, c) for(ll i\
    \ = (ll)(a); i < (ll)(b); i += (ll)(c))\n#define rep(...) SELECT4(__VA_ARGS__,REP4,REP3,REP2,REP1)(__VA_ARGS__)\n\
    #define RREP1(a) for (ll i = (ll)(a)-1; i >= 0; --i)\n#define RREP2(i, a) for\
    \ (ll i = (ll)(a)-1; i >=0; --i)\n#define RREP3(i, a, b) for (ll i = (ll)(a)-1;\
    \ i >= (ll)(b); --i)\n#define rrep(...) SELECT3(__VA_ARGS__,RREP3,RREP2,RREP1)(__VA_ARGS__)\n\
    #define all(x) (x).begin(),(x).end()\n#define rall(x) (x).rbegin(),(x).rend()\n\
    #define SUM(a) accumulate(all(a),0LL)\n#define MIN(a) *min_element(all(a))\n#define\
    \ MAX(a) *max_element(all(a))\n#define INT(...) int __VA_ARGS__;input(__VA_ARGS__)\n\
    #define LL(...) ll __VA_ARGS__;input(__VA_ARGS__)\n#define STR(...) string __VA_ARGS__;input(__VA_ARGS__)\n\
    #define CHR(...) char __VA_ARGS__;input(__VA_ARGS__)\n#define DBL(...) double\
    \ __VA_ARGS__;input(__VA_ARGS__)\n#define LD(...) ld __VA_ARGS__;input(__VA_ARGS__)\n\
    #define pb push_back\n#define eb emplace_back\n#line 3 \"template/alias.hpp\"\n\
    \nusing ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
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
    constexpr int inf = INF<int>;\nconstexpr ld PI = 3.1415926535897932384626;\n#line\
    \ 3 \"template/inout.hpp\"\n\ntemplate<typename T,typename U>\nstd::istream &operator>>(std::istream&is,std::pair<T,U>&p){is>>p.first>>p.second;return\
    \ is;}\ntemplate<typename T>\nstd::istream &operator>>(std::istream&is,std::vector<T>&v){for(T\
    \ &in:v){is>>in;}return is;}\ninline void scan(int &a) { std::cin >> a; }\ninline\
    \ void scan(long long &a) { std::cin >> a; }\ninline void scan(std::string &a)\
    \ { std::cin >> a; }\ninline void scan(char &a) { std::cin >> a; }\ninline void\
    \ scan(double &a) { std::cin >> a; }\ninline void scan(long double &a) { std::cin\
    \ >> a; }\ntemplate <class T, class U>\ninline void scan(std::pair<T, U> &p) {\
    \ std::cin >> p; }\ntemplate <class T>\ninline void scan(std::vector<T> &a) {\
    \ std::cin >> a; }\ninline void input() {}\ntemplate <class Head, class... Tail>\n\
    inline void input(Head &head, Tail &...tail) {scan(head);input(tail...);}\n\n\
    template<typename T>\nstd::ostream &operator<<(std::ostream&os,const std::vector<T>&v){for(auto\
    \ it=std::begin(v);it!=std::end(v);){os<<*it<<((++it)!=std::end(v)?\" \":\"\"\
    );}return os;}\ntemplate<typename T>\nstd::ostream &operator<<(std::ostream&os,const\
    \ std::set<T>&v){for(auto it=std::begin(v);it!=std::end(v);){os<<*it<<((++it)!=std::end(v)?\"\
    \ \":\"\");}return os;}\ntemplate<typename T,typename U>\nstd::ostream &operator<<(std::ostream&os,const\
    \ std::pair<T,U>&p){os<<p.first<<\" \"<<p.second;return os;}\ntemplate<class T>\n\
    inline void print(const T &t){std::cout<<t<<'\\n';}\ntemplate<class Head, class...\
    \ Tail>\ninline void print(const Head &head, const Tail &... tail){std::cout<<head<<'\
    \ ';print(tail...);}\ntemplate<class... T>\ninline void fin(const T &... a){print(a...);exit(0);}\n\
    template<class T>\ninline void printl(const T &t){std::cout<<t<<'\\n';}\ntemplate\
    \ <class T>\ninline void printl(const std::vector<T> &a){for(const auto &v : a)\
    \ std::cout << v << '\\n';}\ntemplate<class Head, class... Tail>\ninline void\
    \ printl(const Head &head, const Tail &... tail){std::cout<<head<<'\\n';printl(tail...);}\n\
    inline void Yes(const bool b = true) { std::cout << (b ? \"Yes\\n\" : \"No\\n\"\
    ); }\ninline void No() { std::cout << \"No\\n\"; }\ninline void YES(const bool\
    \ b = true) { std::cout << (b ? \"YES\\n\" : \"NO\\n\"); }\ninline void NO() {\
    \ std::cout << \"NO\\n\"; }\n\ntemplate<class T>\nvoid trace(const T &t){std::cerr<<t<<')'<<'\\\
    n';}\ntemplate<class Head, class... Tail>\nvoid trace(const Head &head, const\
    \ Tail &... tail){std::cerr<<head<<' ';trace(tail...);}\n#ifdef ONLINE_JUDGE\n\
    #define debug(...) (void(0))\n#else\n#define debug(...) do{std::cerr<<'('<<#__VA_ARGS__<<\"\
    ) = (\";trace(__VA_ARGS__);}while(0)\n#endif\n#line 3 \"template/func.hpp\"\n\n\
    template<class... T>\nconstexpr auto max(T... a){ return max(std::initializer_list<common_type_t<T...>>{a...});\
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
    \        std::swap(x-=t*u,u);\n    }\n    if(x<0)x+=mod;\n    return x;\n}\n#line\
    \ 3 \"tests/joi/joi2009ho_c.test.cpp\"\n\nvoid _main() {\n    INT(N,M,H,K);\n\
    \    vi S(N); input(S);\n    vector P(N,vector<array<int,4>>());\n    //[0]=\u9AD8\
    \u3055\u3001[1]=+-1\u3001[2]=\u305F\u3069\u308A\u7740\u304F\u6570\u3001[3]=\u901A\
    \u308B\u6570\u306E\u500B\u6570\n    rep(i,M){\n        INT(l,h);\n        l--;\n\
    \        P[l].pb({h,1,0,0});\n        P[l+1].pb({h,-1,0,0});\n    }\n    for(auto\
    \ &x:P){\n        sort(all(x));\n    }\n    int sum=0;\n    rep(i,N){\n      \
    \  int x=i,h=0;\n        int now=0;\n        while(1){\n            auto it=lower_bound(all(P[x]),array{h+1,-1,0,0});\n\
    \            if(it==P[x].end()){\n                now=S[x];\n                break;\n\
    \            }\n            h=(*it)[0];\n            x+=(*it)[1];\n        }\n\
    \        x=i,h=0;\n        while(1){\n            int it=lower_bound(all(P[x]),array{h+1,-1,0,0})-P[x].begin();\n\
    \            if(it==P[x].size()){\n                break;\n            }\n   \
    \         if(h!=P[x][it][0]){\n                P[x][it][2]=now;\n            \
    \    if(i<K)\n                    P[x][it][3]++;\n            }\n            h=P[x][it][0];\n\
    \            x+=P[x][it][1];\n        }\n        if(i<K)sum+=now;\n    }\n   \
    \ int ans=sum;\n    rep(i,N)for(auto x:P[i]){\n        int now=sum;\n        array\
    \ it=*lower_bound(all(P[i+x[1]]),array{x[0],-1,0,0});\n        {\n           \
    \ now-=x[2]*x[3];\n            now+=x[3]*it[2];\n        }\n        {\n      \
    \      now-=it[2]*it[3];\n            now+=it[3]*x[2];\n        }\n        chmin(ans,now);\n\
    \    }\n    print(ans);\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/joi2009ho/tasks/joi2009ho_c\"\
    \n#include \"template/template.hpp\"\n\nvoid _main() {\n    INT(N,M,H,K);\n  \
    \  vi S(N); input(S);\n    vector P(N,vector<array<int,4>>());\n    //[0]=\u9AD8\
    \u3055\u3001[1]=+-1\u3001[2]=\u305F\u3069\u308A\u7740\u304F\u6570\u3001[3]=\u901A\
    \u308B\u6570\u306E\u500B\u6570\n    rep(i,M){\n        INT(l,h);\n        l--;\n\
    \        P[l].pb({h,1,0,0});\n        P[l+1].pb({h,-1,0,0});\n    }\n    for(auto\
    \ &x:P){\n        sort(all(x));\n    }\n    int sum=0;\n    rep(i,N){\n      \
    \  int x=i,h=0;\n        int now=0;\n        while(1){\n            auto it=lower_bound(all(P[x]),array{h+1,-1,0,0});\n\
    \            if(it==P[x].end()){\n                now=S[x];\n                break;\n\
    \            }\n            h=(*it)[0];\n            x+=(*it)[1];\n        }\n\
    \        x=i,h=0;\n        while(1){\n            int it=lower_bound(all(P[x]),array{h+1,-1,0,0})-P[x].begin();\n\
    \            if(it==P[x].size()){\n                break;\n            }\n   \
    \         if(h!=P[x][it][0]){\n                P[x][it][2]=now;\n            \
    \    if(i<K)\n                    P[x][it][3]++;\n            }\n            h=P[x][it][0];\n\
    \            x+=P[x][it][1];\n        }\n        if(i<K)sum+=now;\n    }\n   \
    \ int ans=sum;\n    rep(i,N)for(auto x:P[i]){\n        int now=sum;\n        array\
    \ it=*lower_bound(all(P[i+x[1]]),array{x[0],-1,0,0});\n        {\n           \
    \ now-=x[2]*x[3];\n            now+=x[3]*it[2];\n        }\n        {\n      \
    \      now-=it[2]*it[3];\n            now+=it[3]*x[2];\n        }\n        chmin(ans,now);\n\
    \    }\n    print(ans);\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/inout.hpp
  - template/func.hpp
  isVerificationFile: true
  path: tests/joi/joi2009ho_c.test.cpp
  requiredBy: []
  timestamp: '2024-01-20 15:15:56+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/joi/joi2009ho_c.test.cpp
layout: document
---
## 考察
この問題のACの中で最も汚い実装をした自信がある。汚い割には通って良かった(通ってなかったら発狂)。まず、それぞれの横のラインの左側と右側それぞれ、{高さ、左右、たどり着く数、通る数の個数}を持っておく。１つの横のラインを消したとき、合計値を操作すれば良い。全体の計算量は、 $O(NM\log N)$ ぐらい。
