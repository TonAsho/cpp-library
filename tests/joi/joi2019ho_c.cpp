#define PROBLEM "https://atcoder.jp/contests/joi2019ho/tasks/joi2019ho_c"
#include "template/template.hpp"

void _main() {
    INT(N);
    STR(S);
    vi R,G,Y,rr(N),gg(N),yy(N);
    rep(i,N){
        if(i!=0)rr[i]=rr[i-1],gg[i]=gg[i-1],yy[i]=yy[i-1];
        if(S[i]=='R')R.pb(i),rr[i]++;
        else if(S[i]=='G')G.pb(i),gg[i]++;
        else Y.pb(i),yy[i]++;
    }
    vector dp(R.size()+1,vector(G.size()+1,vector(Y.size()+1,vi(3,inf))));
    dp[0][0][0][0]=dp[0][0][0][1]=dp[0][0][0][2]=0;
    rep(r,R.size()+1)rep(g,G.size()+1)rep(y,Y.size()+1)rep(c,3)if(dp[r][g][y][c]!=inf){
        if(c!=0&&(int)R.size()>r){//赤を追加する
            int idx=R[r]+max(r-rr[R[r]],0)+max(g-gg[R[r]],0)+max(y-yy[R[r]],0);
            chmin(dp[r+1][g][y][0],idx-(r+g+y)+dp[r][g][y][c]);
        }        
        if(c!=1&&(int)G.size()>g){//緑を追加する
            int idx=G[g]+max(r-rr[G[g]],0)+max(g-gg[G[g]],0)+max(y-yy[G[g]],0);
            chmin(dp[r][g+1][y][1],idx-(r+g+y)+dp[r][g][y][c]);
        }
        if(c!=2&&(int)Y.size()>y){//黄を追加する
            int idx=Y[y]+max(r-rr[Y[y]],0)+max(g-gg[Y[y]],0)+max(y-yy[Y[y]],0);
            chmin(dp[r][g][y+1][2],idx-(r+g+y)+dp[r][g][y][c]);
        }
    }
    int ans=inf;
    rep(i,3)chmin(ans,dp[R.size()][G.size()][Y.size()][i]);
    if(ans==inf)ans=-1;
    print(ans);
}