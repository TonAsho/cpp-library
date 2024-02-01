#define PROBLEM "https://atcoder.jp/contests/joi2020ho/tasks/joi2020ho_a"
#include "template/template.hpp"

void _main() {
    INT(N);
    vi A(N+1),B(N);input(A,B);
    vi C=A;
    sort(all(C));
    sort(all(B));
    vi LR(N),RL(N);
    {//LR,RL
        rep(i,N){
            LR[i]=max(0,C[i]-B[i]);
            if(i-1>=0)chmax(LR[i],LR[i-1]);
        }
        rrep(i,N){
            RL[i]=max(0,C[i+1]-B[i]);
            if(i+1<N)chmax(RL[i],RL[i+1]);
        }
    }
    unordered_map<int,int> mp;
    rep(i,N+1){
        if(i==0)mp[C[i]]=RL[0];
        else if(i==N)mp[C[i]]=LR[N-1];
        else mp[C[i]]=max(LR[i-1],RL[i]);
    }
    rep(i,N+1){
        if(i!=0)cout<<" ";
        cout<<mp[A[i]];
    }
    cout<<endl;
}