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

TLE: 1s, 256mb

我有一组数量为 $2^k$ 的整数 $a_1,a_2, \cdots ,a_{2^k}$。

现在，我要在找到数组 {$0, 1, \cdots 2^k - 1$} 的两个排列 $p$ 和 $q$，使得它们满足 $a_i = p_i \oplus q_i, \forall i$，或者干脆找不到这样的排列方式。其中 $\oplus$ 代表按位取异或操作。

### 输入

第一行为数列的大小的参数 $k$ ($2 \leq k \leq 12$)。

下一行是 $2^k$ 个整数， $a_1,a_2, \cdots ,a_{2^k}$ ($0 \leq a_i  < 2^k$)。

### 输出

如果找不到排列，输出 “Fou”。

找到了，第一行输出 "Shi"，接下来两行，分别输出两个可行解。

## explain or proof of O(n)

If xor of all elements of the array is not zero, then the answer is "Fou".

Now let's assume that you have two permutations $p,q$ and when xored they are producing an array $a$.

I will show that it is possible to change any two elements $a_i,a_j$ to elements $a_i \oplus x, a_j \oplus x$ with some transformation of the given permutations.

Let's change $a_i,a_j$ to $a_i⊕x$,$a_j⊕x.

Let's find such t, that ai⊕qi=pt.

If t is equal to i or i+1, then you can make some swaps to "fix" the array, to make it satisfy ai=pi⊕qi for all i.

Now you have:

pt,qt,at at position t
pi,qi,ai at position i
pj,qj,aj at position j
Let's make some swaps at these positions to transform it to:

pi,qj,at at position t
pt,qi,ai at position i
pj,qt,aj at position j
Now, after you make these transition, you will have pi⊕qi=ai, and now you need to "fix" positions t and j, and just process recursively.

Lemma: this thing will end in O(n) operations.

______________________________________________________________________________________

Proof: Let's assume that at some two moments you have pt coincided with some pt earlier, let's check the first that moment.

For simplicity of the proof, let's assume that numbers are moving like that:

pt,qi,ai at position t
pi,qj,at at position i
pj,qt,aj at position j
(So pi's are constant, and ai's are changing now. Obviously, it is equivalent to the previous transformation)

Now, assume, that you had numbers:

pt,qt,at at position t
pi,qx,ay at position i (1)
pj,qy,aj at position j (2)
and then, you will make one transformation, and everything will go to:

pt,qx,ay at position t
pi,qy,at at position i
pj,qt,aj at position j
After that, before you will be stuck into described earlier equality:

pt,qx,ay at position t
pi,qv,au at position i
pj,qu,aj at position j
And after swapping with t
pi,qu,ay at position i (3)
pj,qx,aj at position j (4)
Let's look at (1), (2) and (3), (4)

From (1), (2), we can see qy=pi⊕qx⊕ay⊕pj⊕aj
From (3), (4), we can see qu=pi⊕ay⊕pj⊕qx⊕aj
So qy=qu, but u≠y, so it is a contradiction, because q is a permutation.. _________________________________________________________________________________

Ok, using these operations it is pretty simple to get an arbitrary array. Just start with 0,0,…,0 (two equal permutations). And then make ai=bi,ai+1=ai+1⊕(ai⊕bi), at the end you will have one element rest and it will be good because initially xor was zero.

### example

> Input:\
2\
0 1 2 3

- Output:\
Shi\
2 0 1 3\
2 1 3 0

> Input:\
2\
0 1 2 2

- Output:\
Fou


## answer

1, Fou 数组异或和不为零

2, Shi 

(1) $q_i = p_i \oplus a_j$: change $q_i$ and $p_i$

(2) $q_i = p_j \oplus a_i$: change $p_j$

(3) $q_i = p_j \oplus a_j$: change $q_i$ 

(4) All error:
> Find $p_t = a_i \oplus q_i$
> swap these into
> - (i) $p_t, a_i, q_i$ (Right)
> - (j) $p_j, a_j, q_t$
> - (t) $p_i, a_t, q_j$

3, Properties

$a \oplus b = b \oplus a$\
$b \oplus b = 0$\
$a \oplus (c \oplus b) = (a \oplus c) \oplus b$\
$a \oplus b = c \rightarrow b =  c \oplus a$
