# Problem

## source: http://codeforces.com/contest/1168/problem/E

## problem

Toad Mikhail has an array of $2^k$ integers $a_1,a_2, \cdots ,a_{2^k}$.

Find two permutations $p$ and $q$ of integers $0, 1, \cdots ,2k−1$, such that $a_i$ is equal to $p_i \oplus q_i$ for all possible $i$, or determine there are no such permutations. Here $\oplus$ denotes the bitwise XOR operation.

### Input
The first line contains one integer $k$ ($2 \leq k \leq 12$), denoting that the size of the array is $2^k$.

The next line contains $2^k$ space-separated integers $a_1,a_2, \cdots ,a_{2^k}$ ($0 \leq a_i  < 2^k$) — the elements of the given array.

### Output
If the given array can't be represented as element-wise XOR of two permutations of integers $0,1,\cdots,2^k−1$, print "Fou".

Otherwise, print "Shi" in the first line.

The next two lines should contain the description of two suitable permutations. The first of these lines should contain $2^k$ space-separated distinct integers $p_1,p_2,\cdots,p_{2^k}$, and the second line should contain $2^k$ space-separated distinct integers $q_1,q_2,\cdots,q_{2^k}$.

All elements of $p$ and $q$ should be between $0$ and $2^k−1$, inclusive; $p_i \oplus q_i$ should be equal to $a_i$ for all $i$ such that $1 \leq i \leq 2^k$. If there are several possible solutions, you can print any.


## chinese



## explain

## answer