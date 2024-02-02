---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':warning:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':warning:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':warning:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/joi2020ho/tasks/joi2020ho_c
  bundledCode: "#line 1 \"tests/joi/joi2020ho_c.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/joi2020ho/tasks/joi2020ho_c\"\
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
    \ 3 \"tests/joi/joi2020ho_c.cpp\"\n\nvoid _main() {\n    //\u90E8\u5206\u70B9\u3092\
    \u53D6\u308B\u7DF4\u7FD2\u3092\u3057\u3066\u304A\u304F\u3002\n    LL(N,L);\n \
    \   vl X(N+1),T(N+1);\n    //\u5EA7\u6A19\uFF10\u306B\u30B9\u30BF\u30F3\u30D7\u3092\
    \u7F6E\u3044\u3066\u304A\u304F\u3002\n    rep(i,1,N+1)input(X[i]);\n    rep(i,1,N+1)input(T[i]);\n\
    \    bool problem1=true,problem2=true,problem3=true;\n    auto dist=[&](ll a,ll\
    \ b){\n        if(a>b)swap(a,b);\n        return min(b-a,L-b+a);\n    };\n   \
    \ {//\u5C0F\u8AB2\u984C\n        bool T200=true;\n        rep(i,N){\n        \
    \    if(T[i]>200)T200=false;\n        }\n        if(N>12||L>200||!T200)problem1=false;\n\
    \        if(N>15)problem2=false;\n        if(L>200||!T200)problem3=false;\n  \
    \  }\n    if(problem1){\n        N++;\n        vector dp(201,vector(1<<N,vb(N,false)));\n\
    \        //\u6642\u523Bi\u306B\u96C6\u5408j\u306E\u30B9\u30BF\u30F3\u30D7\u3092\
    \u62BC\u3057\u305F\u3068\u304D\u3001\u6700\u5F8C\u306Bk\u3092\u62BC\u3057\u3066\
    \u3044\u308B\u72B6\u614B\u306B\u306A\u308A\u5F97\u308B\u304B\uFF1F\n        //\
    \ \u5EA7\u6A19\uFF10\u306B\u30B9\u30BF\u30F3\u30D7\u304C\u3042\u308B\u3068\u3059\
    \u308B\u3068\u826F\u3055\u305D\u3046\u3002\n        dp[0][1][0]=true;\n      \
    \  rep(i,201)rep(j,1<<N)rep(k,N)if(dp[i][j][k]){\n            rep(l,N){\n    \
    \            if(j>>l&1)continue;\n                int t=dist(X[k],X[l]);\n   \
    \             if(i+t>T[l]||i+t>201)continue;\n                dp[i+t][j|(1<<l)][l]=true;\n\
    \            }\n        }\n        int ans=0;\n        rep(i,201)rep(j,1<<N)rep(k,N)if(dp[i][j][k])chmax(ans,popcnt(j));\n\
    \        print(ans-1);\n    }else if(problem2){\n        N++;\n        vvl dp(1<<N,vl(N,infl));\n\
    \        //\u300C\u96C6\u5408i\u306E\u30B9\u30BF\u30F3\u30D7\u3092\u62BC\u3057\
    \u3066\u3044\u308B\u300D\u304B\u3064\u300C\u6700\u5F8C\u306Bj\u3092\u62BC\u3057\
    \u3066\u3044\u308B\u300D\u72B6\u614B\u306B\u306A\u308B\u307E\u3067\u306E\u6700\
    \u5C0F\u306E\u6642\u9593\n        //\u3053\u308C\u307E\u305F\u5EA7\u6A19\uFF10\
    \u306B\u30B9\u30BF\u30F3\u30D7\u304C\u3042\u308B\u3068\u3059\u308B\u3002\n   \
    \     dp[1][0]=0;\n        rep(i,1<<N)rep(j,N)if(dp[i][j]!=infl){\n          \
    \  rep(k,N){\n                if(i>>k&1)continue;\n                int t=dist(X[j],X[k]);\n\
    \                if(dp[i][j]+t>T[k])continue;\n                chmin(dp[i|(1<<k)][k],dp[i][j]+t);\n\
    \            }\n        }\n        int ans=0;\n        rep(i,1<<N)rep(j,N)if(dp[i][j]!=infl)chmax(ans,popcnt(i));\n\
    \        print(ans-1);\n    }else{\n        N++;\n        //\u5C0F\u8AB2\u984C\
    \uFF13\u3068\uFF14\u306F\u307B\u3068\u3093\u3069\u63DB\u308F\u3089\u306A\u3044\
    \u3002\n        //\u5C0F\u8AB2\u984C\uFF11\u3068\uFF12\u306E\u95A2\u4FC2\u306E\
    \u3088\u3046\u306B\u3001\u6DFB\u3048\u5B57\u3092\u5024\u306B\u6301\u3063\u3066\
    \u304F\u308B\u3068\u4E0A\u624B\u304F\u3044\u304F\u3002\n        vector dpl(N+1,vector(N+1,vector(N+1,infl))),dpr(N+1,vector(N+1,vector(N+1,infl)));\n\
    \        //\u6642\u8A08\u56DE\u308A\u306Bi\u500B\u3001\u53CD\u6642\u8A08\u56DE\
    \u308A\u306Bj\u500B\u306E\u7BC4\u56F2\u3067k\u500B\u306E\u30B9\u30BF\u30F3\u30D7\
    \u3092\u62BC\u3057\u305F\u3068\u304D\u306E\u6700\u5C0F\u306E\u6642\u9593\n   \
    \     dpl[1][0][1]=0;\n        dpr[1][0][1]=0;\n        rep(i,N+1)rep(j,N+1)rep(k,N+1)if(i+j<N){\n\
    \            {//i\u756A\u76EE\u306E\u306E\u30B9\u30BF\u30F3\u30D7\u3092\u62BC\u3059\
    \u3068\u304D\n                if(dpl[i][j][k]!=infl){\n                    ll\
    \ t=dpl[i][j][k]+dist(X[(N-j)%N],X[i]);\n                    chmin(dpr[i+1][j][k+(T[i]>=t)],t);\n\
    \                }\n                if(dpr[i][j][k]!=infl){\n                \
    \    ll t=dpr[i][j][k]+dist(X[(i-1)%N],X[i]);\n                    chmin(dpr[i+1][j][k+(T[i]>=t)],t);\n\
    \                }\n            }\n            {//N-j-1\u756A\u76EE\u306E\u306E\
    \u30B9\u30BF\u30F3\u30D7\u3092\u62BC\u3059\u3068\u304D\n                if(dpl[i][j][k]!=infl){\n\
    \                    ll t=dpl[i][j][k]+dist(X[(N-j)%N],X[(N-j-1)%N]);\n      \
    \              chmin(dpl[i][j+1][k+(T[N-j-1]>=t)],t);\n                }\n   \
    \             if(dpr[i][j][k]!=infl){\n                    ll t=dpr[i][j][k]+dist(X[(i-1)%N],X[(N-j-1)%N]);\n\
    \                    chmin(dpl[i][j+1][k+(T[N-j-1]>=t)],t);\n                }\n\
    \            }\n        }\n        int ans=0;\n        rep(i,N+1)rep(j,N+1)rep(k,N+1){\n\
    \            if(dpl[i][j][k]!=infl)chmax(ans,k);\n            if(dpr[i][j][k]!=infl)chmax(ans,k);\n\
    \        }\n        print(ans-1);\n    }\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/joi2020ho/tasks/joi2020ho_c\"\
    \n#include \"template/template.hpp\"\n\nvoid _main() {\n    //\u90E8\u5206\u70B9\
    \u3092\u53D6\u308B\u7DF4\u7FD2\u3092\u3057\u3066\u304A\u304F\u3002\n    LL(N,L);\n\
    \    vl X(N+1),T(N+1);\n    //\u5EA7\u6A19\uFF10\u306B\u30B9\u30BF\u30F3\u30D7\
    \u3092\u7F6E\u3044\u3066\u304A\u304F\u3002\n    rep(i,1,N+1)input(X[i]);\n   \
    \ rep(i,1,N+1)input(T[i]);\n    bool problem1=true,problem2=true,problem3=true;\n\
    \    auto dist=[&](ll a,ll b){\n        if(a>b)swap(a,b);\n        return min(b-a,L-b+a);\n\
    \    };\n    {//\u5C0F\u8AB2\u984C\n        bool T200=true;\n        rep(i,N){\n\
    \            if(T[i]>200)T200=false;\n        }\n        if(N>12||L>200||!T200)problem1=false;\n\
    \        if(N>15)problem2=false;\n        if(L>200||!T200)problem3=false;\n  \
    \  }\n    if(problem1){\n        N++;\n        vector dp(201,vector(1<<N,vb(N,false)));\n\
    \        //\u6642\u523Bi\u306B\u96C6\u5408j\u306E\u30B9\u30BF\u30F3\u30D7\u3092\
    \u62BC\u3057\u305F\u3068\u304D\u3001\u6700\u5F8C\u306Bk\u3092\u62BC\u3057\u3066\
    \u3044\u308B\u72B6\u614B\u306B\u306A\u308A\u5F97\u308B\u304B\uFF1F\n        //\
    \ \u5EA7\u6A19\uFF10\u306B\u30B9\u30BF\u30F3\u30D7\u304C\u3042\u308B\u3068\u3059\
    \u308B\u3068\u826F\u3055\u305D\u3046\u3002\n        dp[0][1][0]=true;\n      \
    \  rep(i,201)rep(j,1<<N)rep(k,N)if(dp[i][j][k]){\n            rep(l,N){\n    \
    \            if(j>>l&1)continue;\n                int t=dist(X[k],X[l]);\n   \
    \             if(i+t>T[l]||i+t>201)continue;\n                dp[i+t][j|(1<<l)][l]=true;\n\
    \            }\n        }\n        int ans=0;\n        rep(i,201)rep(j,1<<N)rep(k,N)if(dp[i][j][k])chmax(ans,popcnt(j));\n\
    \        print(ans-1);\n    }else if(problem2){\n        N++;\n        vvl dp(1<<N,vl(N,infl));\n\
    \        //\u300C\u96C6\u5408i\u306E\u30B9\u30BF\u30F3\u30D7\u3092\u62BC\u3057\
    \u3066\u3044\u308B\u300D\u304B\u3064\u300C\u6700\u5F8C\u306Bj\u3092\u62BC\u3057\
    \u3066\u3044\u308B\u300D\u72B6\u614B\u306B\u306A\u308B\u307E\u3067\u306E\u6700\
    \u5C0F\u306E\u6642\u9593\n        //\u3053\u308C\u307E\u305F\u5EA7\u6A19\uFF10\
    \u306B\u30B9\u30BF\u30F3\u30D7\u304C\u3042\u308B\u3068\u3059\u308B\u3002\n   \
    \     dp[1][0]=0;\n        rep(i,1<<N)rep(j,N)if(dp[i][j]!=infl){\n          \
    \  rep(k,N){\n                if(i>>k&1)continue;\n                int t=dist(X[j],X[k]);\n\
    \                if(dp[i][j]+t>T[k])continue;\n                chmin(dp[i|(1<<k)][k],dp[i][j]+t);\n\
    \            }\n        }\n        int ans=0;\n        rep(i,1<<N)rep(j,N)if(dp[i][j]!=infl)chmax(ans,popcnt(i));\n\
    \        print(ans-1);\n    }else{\n        N++;\n        //\u5C0F\u8AB2\u984C\
    \uFF13\u3068\uFF14\u306F\u307B\u3068\u3093\u3069\u63DB\u308F\u3089\u306A\u3044\
    \u3002\n        //\u5C0F\u8AB2\u984C\uFF11\u3068\uFF12\u306E\u95A2\u4FC2\u306E\
    \u3088\u3046\u306B\u3001\u6DFB\u3048\u5B57\u3092\u5024\u306B\u6301\u3063\u3066\
    \u304F\u308B\u3068\u4E0A\u624B\u304F\u3044\u304F\u3002\n        vector dpl(N+1,vector(N+1,vector(N+1,infl))),dpr(N+1,vector(N+1,vector(N+1,infl)));\n\
    \        //\u6642\u8A08\u56DE\u308A\u306Bi\u500B\u3001\u53CD\u6642\u8A08\u56DE\
    \u308A\u306Bj\u500B\u306E\u7BC4\u56F2\u3067k\u500B\u306E\u30B9\u30BF\u30F3\u30D7\
    \u3092\u62BC\u3057\u305F\u3068\u304D\u306E\u6700\u5C0F\u306E\u6642\u9593\n   \
    \     dpl[1][0][1]=0;\n        dpr[1][0][1]=0;\n        rep(i,N+1)rep(j,N+1)rep(k,N+1)if(i+j<N){\n\
    \            {//i\u756A\u76EE\u306E\u306E\u30B9\u30BF\u30F3\u30D7\u3092\u62BC\u3059\
    \u3068\u304D\n                if(dpl[i][j][k]!=infl){\n                    ll\
    \ t=dpl[i][j][k]+dist(X[(N-j)%N],X[i]);\n                    chmin(dpr[i+1][j][k+(T[i]>=t)],t);\n\
    \                }\n                if(dpr[i][j][k]!=infl){\n                \
    \    ll t=dpr[i][j][k]+dist(X[(i-1)%N],X[i]);\n                    chmin(dpr[i+1][j][k+(T[i]>=t)],t);\n\
    \                }\n            }\n            {//N-j-1\u756A\u76EE\u306E\u306E\
    \u30B9\u30BF\u30F3\u30D7\u3092\u62BC\u3059\u3068\u304D\n                if(dpl[i][j][k]!=infl){\n\
    \                    ll t=dpl[i][j][k]+dist(X[(N-j)%N],X[(N-j-1)%N]);\n      \
    \              chmin(dpl[i][j+1][k+(T[N-j-1]>=t)],t);\n                }\n   \
    \             if(dpr[i][j][k]!=infl){\n                    ll t=dpr[i][j][k]+dist(X[(i-1)%N],X[(N-j-1)%N]);\n\
    \                    chmin(dpl[i][j+1][k+(T[N-j-1]>=t)],t);\n                }\n\
    \            }\n        }\n        int ans=0;\n        rep(i,N+1)rep(j,N+1)rep(k,N+1){\n\
    \            if(dpl[i][j][k]!=infl)chmax(ans,k);\n            if(dpr[i][j][k]!=infl)chmax(ans,k);\n\
    \        }\n        print(ans-1);\n    }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/inout.hpp
  - template/func.hpp
  isVerificationFile: false
  path: tests/joi/joi2020ho_c.cpp
  requiredBy: []
  timestamp: '2024-02-02 10:54:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tests/joi/joi2020ho_c.cpp
layout: document
title: joi2020ho_c
---
## 考察
難易度９の自力ACはかなり(≧∀≦)。小課題での考察を融合して答えにたどり着いた。本番もこのムーブをしたい。小課題があることがAtCoderとの最大の違いかもしれない。小課題は問題のヒントだと実感。

解法はコメントで分かりやすく書いている（つもり）よ