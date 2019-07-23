# source http://codeforces.com/problemset/problem/571/E

## Usage

2-versions: old(with multi data); new(with only 1 time run)

1. `g++ code.cpp`(standard, can not change name or in gen.sh)
2. `python gen.py`, gen .in files
3. `./gen.sh`, gen .out files
4. `g++ specialJudge.cpp -o s.out | ./s.oout < file-name`, check special !!!! not support for `-1` type (-1 is only-one solution)

Geometric progression with the first element a and common ratio b is a sequence of numbers a, ab, ab2, ab3, ....

You are given n integer geometric progressions. Your task is to find the smallest integer x, that is the element of all the given progressions, or else state that such integer does not exist.

Input
The first line contains integer (1 ≤ n ≤ 100) — the number of geometric progressions.

Next n lines contain pairs of integers a, b (1 ≤ a, b ≤ 109), that are the first element and the common ratio of the corresponding geometric progression.

Output
If the intersection of all progressions is empty, then print  - 1, otherwise print the remainder of the minimal positive integer number belonging to all progressions modulo 1000000007 (109 + 7).

## chinese version

给出两个整数 $a, b$，由此生成一个序列$A = {a * b^{n-1}},\ n \in \mathbb{N}$。

现在给出一组$a_i, b_i,\ i \in [1,k]$，由此生成$k$组序列，试图找出最小的$x$使得$x$同时是以上所有组的元素，即$x \in A_i \forall i \in [1,k]$。

注意，上述的$i$为整数。

### 输入

一个整数$k$， $(1 \leq k \leq 100)$。

$k$行，每行两个整数 $a_i, b_i,\ 1 \leq a_i, b_i \leq 10^9$。

### 输出

一个整数 $t = x\ mod\ 1e9 + 7$。

如果没有这样的解，输出$-1$。

### 举例

输入：
2
2 2
4 1
输出：
4
输入：
2
2 2
3 3
输出：
-1

## explain


571E - Geometric Progressions

If intersection of two geometric progressions is not empty, set of common elements indexes forms arithmetic progression in each progression or consists of not more than one element. Let's intersect first progression with each other progression. If any of these intersections are empty then total intersection is empty. If some of these intersection consist of one element, then we could check only this element. Otherwise one could intersect arithmetic progressions of first progression indexes and take minimal element of this intersection. The remaining question is how intersect two geometric progression? Let's factorise all numbers in these two progressions and find set of appropriate indexes for every prime factor in both progressions. These progressions one need intersect both by values and by indexes.

Problem author: zeliboba.

Problem developers: zeliboba, yarrr, gchebanov.

## answer

