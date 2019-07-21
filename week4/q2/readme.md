## USage

2-versions: old(with multi data); new(with only 1 time run)

1. `g++ code.cpp`(standard, can not change name or in gen.sh)
2. `python gen.py`, gen .in files
3. `./gen.sh`, gen .out files
4. `g++ specialJudge.cpp -o s.out | ./s.oout < file-name`, check special !!!! not support for `-1` type (-1 is only-one solution)




## source http://codeforces.com/contest/1120/problem/E


## The very same Munchhausen

A positive integer $a$ is given. Baron Munchausen claims that he knows such a positive integer $n$ that if one multiplies $n$ by $a$, the sum of its digits decreases $a$ times. In other words, $S(an)=S(n)/a$, where $S(x)$ denotes the sum of digits of the number $x$.

Find out if what Baron told can be true.


### Input

The only line contains a single integer $a$ $(2 \leq a \leq 10^3)$.

### Output

If there is no such number $n$, print `−1`.

Otherwise print any appropriate positive integer $n$. Your number must not consist of more than $5*10^5$ digits. We can show that under given constraints either there is no answer, or there is an answer no longer than $5*10^5$ digits.


## chinese version

有多个解！！

给出 $a$, 求出这样的$n$，满足 $S(an)=S(n)/a$，其中 $S(x)$ 就是 x 以十进制表示的时候的所有位的和。

### 输入

一个整数$a$， $(2 \leq a \leq 10^3)$。


### 输出

一个整数 $n$，n的位数小于$5*10^5$。如果没有这样的解，输出-1。


注意：我们保证如果有解，那么解的答案的位数一定小于$5*10^5$。

### 举例

输入：
2
输出：
输入：
10
输出：
-1

## explain

Define the balance of a number $x$ as $S(nx)*n−S(x)$. By the balance of a digit string we mean the balance of the corresponding number.

Solution 1. We are gonna do the following:

Find out if the solution exists. If no, print `-1` and exit.

Find any string with negative balance.

Find any string with positive balance.

Take their linear combination with zero balance (maybe we pad the numbers we found by leading zeroes before this). By linear combination of several strings we mean their concatenation where each of them can occur several times.

It is quite clear how to perform the last step. To perform the initial step it's convenient to introduce some lemmas.

Lemma 1. $S(a+b)\leq S(a)+S(b)$.

Proof. It's obvious more or less since if we write both numbers one under another and start calculating their sum then the result will have sum of digits being equal to $S(a)+S(b)$ minus 9 times the number of carries.

Lemma 2. $S(ab) \leq aS(b)$.

Proof. $S(ab)=S(b+b+\cdots +b)\leq S(b)+S(b)+\cdots S(b)=aS(b)$. Here the inequality holds according to Lemma 1.

Lemma 3. $S(ab) \leq S(a)S(b)$.

Proof. Let $a=ave(a_{n−1}a_{n−2}\cdots t a_1 a_0 )$, Then

$$
S(ab) = S(a_{n−1}b*10^{n−1} + a_{n−2}b*10^{n−2}+\cdots +a_0b) \\
\leq  S(a_{n−1}b*10^{n−1} + S(a_{n−2}b*10^{n−2})+\cdots +S(a_0b) \\
= S(a_{n−1}b)+S(a_{n−2}b)+\cdots +S(a_0b)\\
\leq (a_{n−1}+a_{n−2}+\cdots+a_0) S(b) = S(a)S(b).
$$


Now consider two cases.

$a=2^{d1}5^{d2}$, Let $b=10^{max(d1,d2)}$. One can see that

$aS(an)=aS(\frac{bn}{b/a})=aS(b/a)S(b/a)S(\frac{bn}{b/a})\geq aS(b/a)S(bn)=aS(b/a)S(n)$.

That means that if $a>S(b/a)$ then the answer doesn't exist, otherwise the number $b/a$ has non-positive balance. One can easily see that the number 1 always has non-negative balance, so in this case the problem is solved.

$a$ has a prime divisor which is not 2 and not 5.

It turns out that in this case the answer always exists. Indeed, the decimal fraction $1/a$ is infinite, that means that $S(\frac{10^k}{a})$ in nondecreasing and can be sufficiently large; and so can be$S(\frac{10^k}{a} + 1)$ since the number of trailing $9-s$ of $\frac{10^k}{a}$ is bounded. Meanwhile$S(a*(\frac{10^k}{a} + 1))$ is bounded by, say, $1+9len(a)$, so we always can find a string with negative balance, and, as we mentioned above, the number $1$ always has nonnegative balance.

We know two ways to perform the second step.

Divide 1 by a and find the period. Let's say that the period can be represented as a string s and the part before it by a string t (possibly empty). Let s′ have the same length as s and equal (s+1) when being treated as an integer. We are looking for a string of type tsss…ss′ with negative balance. One can calculate the impact on balance of strings t, s and s′ and therefore find the minimal required number of stings s.

Construct a weighted directed graph. Its vertices are numbers from 0 to a−1, and for each pair of numbers (c,x)≠(0,0) with 0≤c<a and 0≤x≤9 there is an edge from c to ⌊ax+c10⌋ with weight (ax+c)(mod10) and label x. Informally, if we traverse through some path from 0, and labels of the edges on this path are digits of some number n from right to left, then the sum of weights are the current balance of an (that is, if we consider only last len(n) digits when calculating the balance) and the last vertex represents the current carry. Now we can find a negative cycle in this graph via Ford-Bellman algorithm and then construct a path from 0 to this cycle, go through the cycle required number of times (so that the final sum of weights is negative) and then return to the zero vertex.

This solution has a disadvantage: the final answer can have a length up to S(n)⋅n2. One workaround is to find, say, 300 different possibilities of negative balance (by taking more periods/negative cycles) and find the positive balance string by trying all numbers from 1 to 10000 and constructing a string with a small balance divisible by any of negative balances. It can be done by a sort of knapsack on found positive balances. The idea is to get a big gcd of the two found balances so that we don't need to repeat the negative-balance-string too many times (because among the two found strings it is the one which can have a superlinear length).

Solution 2. Imagine we have infinite time and memory. Then we can say that we have states of kind (carry,balance) similar to the states of the graph from solution 1, where for each state (carry,balance) and each digit x (except state (0,0) and digit 0 at the same time) there is a transition to ((carry+a⋅x)(mod10),balance+a⌊carry+a⋅x10⌋−x). Our goal is to reach (0,0) again. One can bfs over this (infinite) graph with creating new states, when needed. However, traversing over this graph consume too much memory.

It turns out that if we don't consider states with |balance|>a then there always is a solution, and this is relatively easy to come up with (and definitely easier to pass than the previous one).

## answer

