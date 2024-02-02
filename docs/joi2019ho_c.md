---
title: joi2019ho_c
documentation_of: //tests/joi/joi2019ho_c.cpp
---
## 考察
操作後の文字列を `T` とする。

$dp_{r,g,y,c}$ を、`T` の先頭から $r+g+y$  番目までに、赤を $r$ 個、緑を $g$ 個、黄を $y$ 個使って、最後の色が $c$ の時の、操作回数の最小値とする。

遷移を考える。

赤玉を追加するとき、それとペアとなるのは `S` の $R_r$ 番目の文字である。しかし、赤を $r$ 個、緑を $g$ 個、黄を $y$ 個、既に前に移動させているので、`S` の $R_r$ 番目の文字は後方に移動してしまう(または動かない)。

これより、 `S` の $i$ 番目の文字の前にある各色の個数、$r_i$ , $g_i$ , $y_i$ ,を計算しておくと、`S` の $R_r$ 番目の文字は移動後  $R_r+max(r-r_{R_i},0)+max(g-g_{R_i},0)+max(y-y_{R_i},0)$ 番目に移動すると分かった。

あとは実装！