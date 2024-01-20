#define PROBLEM "https://atcoder.jp/contests/joi2015yo/tasks/joi2015yo_e"
#include "template/template.hpp"

const int dx[8]={-1,-1,-1,0,0,1,1,1};
const int dy[8]={-1,0,1,-1,1,-1,0,1};
void _main() {
    INT(H,W);
    vs S(H); input(S);
    vvi cnt(H,vi(W));
    vvb vis(H,vb(W,false));
    vector<pii> P1;
    rep(i,H)rep(j,W)if(S[i][j]!='.'){
        rep(k,8){
            int h=i+dx[k],w=j+dy[k];
            if(h<0||h>=H||w<0||w>=W)continue;
            if(S[h][w]=='.')cnt[i][j]++;
        }
        if(S[i][j]-'0'<=cnt[i][j]&&!vis[i][j]){
            vis[i][j]=true;
            P1.eb(i,j);
        }
    }
    int ans=1;
    while(1){
        for(auto &[i,j]:P1)S[i][j]='.';
        vector<pii> P2;
        bool flg=false;
        for(auto &[i,j]:P1){
            rep(k,8){
                int h=i+dx[k],w=j+dy[k];
                if(h<0||h>=H||w<0||w>=W)continue;
                if(S[h][w]=='.')continue;
                cnt[h][w]++;
                if(S[h][w]-'0'<=cnt[h][w]&&!vis[h][w]){
                    vis[h][w]=true;
                    flg=true;
                    P2.eb(h,w);
                }
            }   
        }
        if(!flg)break;
        ans++;
        swap(P1,P2);
    }
    print(ans);
}