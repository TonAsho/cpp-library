#pragma once
#include <bits/stdc++.h>
#include "graph/graph-template.hpp"
/**
 * @brief EulerTour
 */
template<typename T>
struct EulerTour : Graph<T> {
  private:
    struct RMQ {
        int n, s;
        using P = std::pair<int, int>;
        std::vector<P> seg;
        P UNIT = P(1 << 30, -1);
        RMQ() = default;
        void build(const std::vector<P> &v) {
            n = v.size();
            s = 1;
            while (s < n) s <<= 1;
            seg.assign(s << 1, UNIT);
            for(int i = 0; i < n; i++) seg[i + s] = v[i];
            for (int k = s - 1; k > 0; k--) {
                seg[k] = std::min(seg[k << 1], seg[(k << 1) + 1]);
            }
        }
        P query(int a, int b) const {
            P R = UNIT;
            for (a += s, b += s; a < b; a >>= 1, b >>= 1) {
                if (a & 1) R = std::min(R, seg[a++]);
                if (b & 1) R = std::min(R, seg[--b]);
            }
            return R;
        }
        int size() const { return n; }
    };
    int cnt;
    std::vector<int> dep;
    std::vector<std::pair<int, int>> idx, rmqvec;
    RMQ rmq;
    void dfs(int v, int p) {
        idx[v].first = cnt++;
        rmqvec.emplace_back(dep[v], v);
        for(auto &e : g[v]) {
            if(e == p) continue;
            dep[e] = dep[v] + 1;
            dfs(e, v);
            rmqvec.emplace_back(dep[v], v);
        }
        idx[v].second = cnt++;
    }
  public:   
    using Graph<T>::g;
    EulerTour(int n) : Graph<T>(n) {}
    void build(int root) {
        idx.assign(g.size(), {-1, -1});
        dep.assign(g.size(), 0);
        rmqvec.reserve((int)g.size() << 1);
        cnt = 0;
        dfs(root, -1);
        rmq.build(rmqvec);
    }
    std::pair<int, int> get_idx(int k) const { return idx[k]; }
    int lca(int u, int v) const {
        if(idx[u].first > idx[v].first) std::swap(u, v);
        return rmq.query(idx[u].first, idx[v].first + 1).second;
    }
    template<class F>
    void each_vertex_subtree(int v, const F &f) const {
        f(idx[v].first, idx[v].second + 1);
    }
    template<class F>
    void each_edge_subtree(int v, const F &f) const {
        f(idx[v].first + 1, idx[v].second + 1);
    }
    template<class F>
    void each_vertex(int u, int v, const F &f) const {
        int l = lca(u, v);
        f(idx[l].first, idx[u].first + 1);
        f(idx[l].first + 1, idx[v].first + 1);
    }
    template<class F>
    void each_edge(int u, int v, const F &f) const {
        int l = lca(u, v);
        f(idx[l].first + 1, idx[u].first + 1);
        f(idx[l].first + 1, idx[v].first + 1);
    }
    int size() const { return (int)(g.size()); }
};