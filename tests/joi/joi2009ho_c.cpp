#define PROBLEM "https://atcoder.jp/contests/joi2009ho/tasks/joi2009ho_c"
#include "template/template.hpp"

void _main() {
    //そこから始めたら何になるか
    //そこを通るやつの数
    INT(N,M,H,K);
    vi S(N); input(S);
    vector P(N,vector<array<int,4>>());
    //[0]=高さ、[1]=+-1、[2]=たどり着く数、[3]=通る数の個数
    rep(i,M){
        INT(l,h);
        l--;
        P[l].pb({h,1,0,0});
        P[l+1].pb({h,-1,0,0});
    }
    for(auto &x:P){
        sort(all(x));
    }
    int sum=0;
    rep(i,N){
        int x=i,h=0;
        int now=0;
        while(1){
            auto it=lower_bound(all(P[x]),array{h+1,-1,0,0});
            if(it==P[x].end()){
                now=S[x];
                break;
            }
            h=(*it)[0];
            x+=(*it)[1];
        }
        x=i,h=0;
        while(1){
            int it=lower_bound(all(P[x]),array{h+1,-1,0,0})-P[x].begin();
            if(it==P[x].size()){
                break;
            }
            if(h!=P[x][it][0]){
                P[x][it][2]=now;
                if(i<K)
                    P[x][it][3]++;
            }
            h=P[x][it][0];
            x+=P[x][it][1];
        }
        if(i<K)sum+=now;
    }
    int ans=sum;
    rep(i,N)for(auto x:P[i]){
        int now=sum;
        array it=*lower_bound(all(P[i+x[1]]),array{x[0],-1,0,0});
        {
            now-=x[2]*x[3];
            now+=x[3]*it[2];
        }
        {
            now-=it[2]*it[3];
            now+=it[3]*x[2];
        }
        chmin(ans,now);
    }
    print(ans);
}