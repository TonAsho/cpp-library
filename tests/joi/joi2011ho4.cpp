#define PROBLEM "https://atcoder.jp/contests/joi2011ho/tasks/joi2011ho4"
#include "template/template.hpp"

void _main() {
    INT(H,W,N);
    vi X(N),Y(N);
    rep(i,N)input(X[i],Y[i]);
    vector<pii> P;
    {
        vi XX=X,YY=Y;
        sort(all(XX));
        sort(all(YY));
        if(N%2==0){
            P.eb(XX[N/2-1],YY[N/2-1]);
            P.eb(XX[N/2-1],YY[N/2]);
            P.eb(XX[N/2],YY[N/2-1]);
        }
        P.eb(XX[N/2],YY[N/2]);
    }
    ll ans=infl;
    int ans_x,ans_y;
    for(auto &[x,y]:P){
        ll now=0;
        int mx=0;
        rep(i,N){
            now+=abs(x-X[i])+abs(y-Y[i]);
            chmax(mx,abs(x-X[i])+abs(y-Y[i]));
        }
        if(chmin(ans,now*2-mx)){
            ans_x=x,ans_y=y;
        }
    }
    print(ans);
    print(ans_x,ans_y);
}
