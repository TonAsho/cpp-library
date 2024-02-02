#define PROBLEM "https://atcoder.jp/contests/joi2019ho/tasks/joi2019ho_b"
#include "template/template.hpp"

void _main() {
    INT(N,M);
    priority_queue<pii> Q;
    rep(i,N){
        INT(s,v);
        Q.emplace(v,s);
    }
    vi C(M);input(C);
    sort(all(C));
    int ans=0;
    while(!Q.empty()){
        auto [v,s]=Q.top();Q.pop();
        if(C.empty())break;
        if(C.back()>=s){
            C.pop_back();
            ans++;
        }
    }
    print(ans);
}