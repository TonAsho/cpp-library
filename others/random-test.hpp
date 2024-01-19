#pragma once
#include <bits/stdc++.h>
struct RandomTest {
  private:
    std::random_device rd;
    std::mt19937 mt;
  public:
    RandomTest() { mt.seed(rd()); }
    long long get_int(long long mn, long long mx) {
        mx++;
        int res = mt() % mx;
        while(res < mn) res = mt() % mx;
        return res;
    }
    template<typename T>
    std::vector<T> get_vec(long long mn, long long mx, int size) {
        std::vector<T> res(size);
        for(int i = 0; i < size; i++) res[i] = get_int(mn, mx);
        return res;
    }
};