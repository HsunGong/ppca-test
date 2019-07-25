# source http://codeforces.com/problemset/problem/571/E

## Usage

1, catch.py to get data
2, gen.py to gen easy data and diff data 'use error code'
3, gen_out.py to gen answer
4, append data with gen2.py

## Problem
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

一共有$n$组数据，代表上述问题重复$n$次。

### 范围

20% $k \leq 3$

35% $k \leq 40$

45% $k \leq 100$

### 输入

第一行，一个整数$n$， $(1 \leq n \leq 10)$。

之后$n$组，每一组数据形式如下：

第一行，一个整数$k$， $(1 \leq k \leq 100)$。

之后 $k$行，每行两个整数 $a_i, b_i,\ 1 \leq a_i, b_i \leq 10^9$。

### 输出

一共$n$行，每行一个整数$t$，$t = x\ mod\ 1e9 + 7$，可行解$x$；如果没有这样的解，输出$-1$。

### 举例

输入：
```
2
2
2 2
4 1
2
2 2
3 3
```
输出：
```
4
-1
```

## explain


571E - Geometric Progressions

If intersection of two geometric progressions is not empty, set of common elements indexes forms arithmetic progression in each progression or consists of not more than one element. Let's intersect first progression with each other progression. If any of these intersections are empty then total intersection is empty. If some of these intersection consist of one element, then we could check only this element. Otherwise one could intersect arithmetic progressions of first progression indexes and take minimal element of this intersection. The remaining question is how intersect two geometric progression? Let's factorise all numbers in these two progressions and find set of appropriate indexes for every prime factor in both progressions. These progressions one need intersect both by values and by indexes.

Problem author: zeliboba.

Problem developers: zeliboba, yarrr, gchebanov.

## answer

