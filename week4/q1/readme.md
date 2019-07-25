
## source http://codeforces.com/problemset/problem/963/E

## Circles of Waiting

A chip was placed on a field with coordinate system onto point $(0, 0)$.

Every step the chip moves randomly. If the chip is currently at a point $(x, y)$, after a step it moves to the point $(x - 1, y)$ with probability $p_1$, to the point $(x, y - 1)$ with probability $p_2$, to the point $(x + 1, y)$ with probability $p_3$ and to the point $(x, y + 1)$ with probability $p_4$. It's guaranteed that $p_1 + p_2 + p_3 + p_4 = 1$. The moves are independent.

Find out the expected steps after which chip will move away from origin at a distance greater than $R$ (i.e.  will be satisfied).

### Input

First line contains five integers $R, a_1, a_2, a_3, a_4,\ (0 \leq R \leq 50, 1 \leq a_1, a_2, a_3, a_4 \leq 1000)$.

Probabilities $p_i$ can be calculated using formula $p_i = \frac{a_i}{a_1+a_2+a_3+a_4}$.

### Output

It can be shown that answer for this problem is always a rational number of form $\frac{P}{Q} mod\ 10^9+7$, where $Q \neq 0$.

Print $P*Q^{-1}\ mod\ 10^9 + 7$

## chinese version

一个点从原点出发，每走一步（步长为1），有四个方向上下左右，按照四个方向走的概率分别为：$p_1, p_2, p_3, p_4$，四个概率加起来是$1$，也就是说，保证不会原地踏步。

求：这个点要走出半径为$R$的圆的步数的期望。

### 输入

5个数，第一个，半径$R$， 后面四个 $a_1, a_2, a_3, a_4,\ (0 \leq R \leq 50, 1 \leq a_1, a_2, a_3, a_4 \leq 1000)$

$p_i = \frac{a_i}{a_1+a_2+a_3+a_4}$

### 输出

将期望用有理数形式表示 输出 $P*Q^{-1}\ mod\ 10^9 + 7$ , where $Q \neq 0$.

### 数据范围

50%,  $R < 20$

50%,  $R < 50$

### 样例

输入：
0 1 1 1 1

输出：
1

输入：
1 1 1 1 1

输出：
666666674

- 解释：
P/Q = 8/3, inverse of Q is $(Q*Q^-1) \equiv 1 mod m$

## explain

Let's call a sell "good", if for its coordinates the following condition is satisfied x2 + y2 ≤ R2.

For each good cell we consider the equation of its expected value:

f(x, y) = p1·f(x - 1, y) + p2·f(x, y + 1) + p3·f(x + 1, y) + p4·f(x, y - 1) + 1.

Then this problem can be reduced to solving the system of linear equations.

We can do this using Gauss's method with a complexity of O(R6), but this solution gets TL.

Now, we can see that we only need to calculate f(0, 0). So we will handle cells top down. While handling each row, we will relax values of all previous rows and a row of cell (0;0). Also we will iterate only for non-zero elements of each row. This solution has a complexity of O(R4).

Prove of the complexity:

Let's dye yellow all cells that we have already passed, green - all cells adjacent to them and black - all other cells. Then next cell which we will add is green. Note that its equation(for a moment of adding) doesn't include yellow cells. It consists of initially adjacent black cells and green cells. It's not hard to see, that then row includes only O(R) non-zero elements and the current green cell is inside of O(R) not visited rows. So one row in Gauss's method is handled inO(R2) and there are O(R2) rows. That's why this Gauss's method works in O(R4).



## answer

