#define PROBLEM "https://atcoder.jp/contests/joi2020ho/tasks/joi2020ho_c"
#include "template/template.hpp"

void _main() {
    //部分点を取る練習をしておく。
    LL(N,L);
    vl X(N+1),T(N+1);
    //座標０にスタンプを置いておく。
    rep(i,1,N+1)input(X[i]);
    rep(i,1,N+1)input(T[i]);
    bool problem1=true,problem2=true,problem3=true;
    auto dist=[&](ll a,ll b){
        if(a>b)swap(a,b);
        return min(b-a,L-b+a);
    };
    {//小課題
        bool T200=true;
        rep(i,N){
            if(T[i]>200)T200=false;
        }
        if(N>12||L>200||!T200)problem1=false;
        if(N>15)problem2=false;
        if(L>200||!T200)problem3=false;
    }
    if(problem1){
        N++;
        vector dp(201,vector(1<<N,vb(N,false)));
        //時刻iに集合jのスタンプを押したとき、最後にkを押している状態になり得るか？
        // 座標０にスタンプがあるとすると良さそう。
        dp[0][1][0]=true;
        rep(i,201)rep(j,1<<N)rep(k,N)if(dp[i][j][k]){
            rep(l,N){
                if(j>>l&1)continue;
                int t=dist(X[k],X[l]);
                if(i+t>T[l]||i+t>201)continue;
                dp[i+t][j|(1<<l)][l]=true;
            }
        }
        int ans=0;
        rep(i,201)rep(j,1<<N)rep(k,N)if(dp[i][j][k])chmax(ans,popcnt(j));
        print(ans-1);
    }else if(problem2){
        N++;
        vvl dp(1<<N,vl(N,infl));
        //「集合iのスタンプを押している」かつ「最後にjを押している」状態になるまでの最小の時間
        //これまた座標０にスタンプがあるとする。
        dp[1][0]=0;
        rep(i,1<<N)rep(j,N)if(dp[i][j]!=infl){
            rep(k,N){
                if(i>>k&1)continue;
                int t=dist(X[j],X[k]);
                if(dp[i][j]+t>T[k])continue;
                chmin(dp[i|(1<<k)][k],dp[i][j]+t);
            }
        }
        int ans=0;
        rep(i,1<<N)rep(j,N)if(dp[i][j]!=infl)chmax(ans,popcnt(i));
        print(ans-1);
    }else{
        N++;
        //小課題３と４はほとんど換わらない。
        //小課題１と２の関係のように、添え字を値に持ってくると上手くいく。
        vector dpl(N+1,vector(N+1,vector(N+1,infl))),dpr(N+1,vector(N+1,vector(N+1,infl)));
        //時計回りにi個、反時計回りにj個の範囲でk個のスタンプを押したときの最小の時間
        dpl[1][0][1]=0;
        dpr[1][0][1]=0;
        rep(i,N+1)rep(j,N+1)rep(k,N+1)if(i+j<N){
            {//i番目ののスタンプを押すとき
                if(dpl[i][j][k]!=infl){
                    ll t=dpl[i][j][k]+dist(X[(N-j)%N],X[i]);
                    chmin(dpr[i+1][j][k+(T[i]>=t)],t);
                }
                if(dpr[i][j][k]!=infl){
                    ll t=dpr[i][j][k]+dist(X[(i-1)%N],X[i]);
                    chmin(dpr[i+1][j][k+(T[i]>=t)],t);
                }
            }
            {//N-j-1番目ののスタンプを押すとき
                if(dpl[i][j][k]!=infl){
                    ll t=dpl[i][j][k]+dist(X[(N-j)%N],X[(N-j-1)%N]);
                    chmin(dpl[i][j+1][k+(T[N-j-1]>=t)],t);
                }
                if(dpr[i][j][k]!=infl){
                    ll t=dpr[i][j][k]+dist(X[(i-1)%N],X[(N-j-1)%N]);
                    chmin(dpl[i][j+1][k+(T[N-j-1]>=t)],t);
                }
            }
        }
        int ans=0;
        rep(i,N+1)rep(j,N+1)rep(k,N+1){
            if(dpl[i][j][k]!=infl)chmax(ans,k);
            if(dpr[i][j][k]!=infl)chmax(ans,k);
        }
        print(ans-1);
    }
}