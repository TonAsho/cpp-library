#define PROBLEM "https://atcoder.jp/contests/joi2020ho/tasks/joi2020ho_b"
#include "template/template.hpp"

void _main() {
    INT(N,K);
    STR(S);
    vi A,B,C;
    rep(i,N){
        if(S[i]=='J')A.pb(i);
        else if(S[i]=='O')B.pb(i);
        else C.pb(i);
    }
    if(A.size()<K)fin(-1);
    int ans=inf;
    rep(i,A.size()){
        if(i+K-1<(int)A.size()){
            int Ar=A[i+K-1];
            int idx=lower_bound(all(B),Ar)-B.begin();
            if(idx+K-1<(int)B.size()){
                int Br=B[idx+K-1];
                idx=lower_bound(all(C),Br)-C.begin();
                if(idx+K-1<(int)C.size()){
                    chmin(ans,(C[idx+K-1]-A[i]+1)-K*3);
                }
            }
        }
    }
    if(ans==inf)ans=-1;
    print(ans);
}