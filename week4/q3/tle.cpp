#include <cstdio>
using namespace std;
int tot, num, a[110][110], b[110][110], n, ans[110], p[110], N = 100000, prime[100010], st[110], aa[110], bb[110];
bool is[100010], flag = 0;
long long P = 1000000007, ANS = 1, modd, rem, d;
long long sqr(long long x) { return x * x % P; }
long long pow(long long a, long long n)
{
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return sqr(pow(a, n / 2));
	return sqr(pow(a, n / 2)) * a % P;
}
long long gcd(long long a, long long b)
{
	if (a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}
void print()
{
	ANS = 1;
	int i, j;
	for (j = 1; j <= n; j++)
		if (ans[j] >= 0)
			break;
	for (i = 1; i <= num; i++)
	{
		ANS = ANS * pow(p[i], a[i][j] + ans[j] * b[i][j]) % P;
	}
	printf("%lld\n", ANS);
}
void find_prime()
{
	int i, j;
	for (i = 2; i * i <= N; i++)
		if (!is[i])
		{
			for (j = i; j * i <= N; j++)
				is[i * j] = 1;
		}
	for (i = 2; i <= N; i++)
		if (!is[i])
		{
			tot++;
			prime[tot] = i;
		}
}
void factor(int aa, int bb)
{
	int temp;
	for (int i = 1; i <= tot; i++)
	{
		if (aa == 1 && bb == 1)
			return;
		if (aa % prime[i] != 0 && bb % prime[i] != 0)
			continue;
		num++;
		p[num] = prime[i];
		temp = 0;
		while (aa % prime[i] == 0)
		{
			aa /= prime[i];
			temp++;
		}
		a[num][1] = temp;
		temp = 0;
		while (bb % prime[i] == 0)
		{
			bb /= prime[i];
			temp++;
		}
		b[num][1] = temp;
	}
	if (aa > 1)
	{
		num++;
		p[num] = aa;
		a[num][1] = 1;
	}
	if (bb > 1)
	{
		if (bb == aa)
			b[num][1] = 1;
		else
		{
			num++;
			p[num] = bb;
			b[num][1] = 1;
		}
	}
}
void factoring1(int k, int &n)
{
	for (int i = 1; i <= num; i++)
	{
		if (n % p[i] != 0)
			continue;
		int temp = 0;
		while (n % p[i] == 0)
		{
			n /= p[i];
			temp++;
		}
		a[i][k] = temp;
		if (n == 1)
			break;
	}
}
void factoring2(int k, int &n)
{
	for (int i = 1; i <= num; i++)
	{
		if (n % p[i] != 0)
			continue;
		int temp = 0;
		while (n % p[i] == 0)
		{
			n /= p[i];
			temp++;
		}
		b[i][k] = temp;
		if (n == 1)
			break;
	}
}
bool check()
{
	int i, j, k, tt;
	for (j = 1; j <= n; j++)
	{
		if (ans[j] >= 0)
			break;
	}
	for (i = 1; i <= num; i++)
	{
		st[i] = a[i][j] + b[i][j] * ans[j];
	}
	for (k = 1; k <= n; k++)
	{
		if (k == j)
			continue;
		for (int i = 1; i <= num; i++)
			if (b[i][k] != 0)
				break;
		if (b[i][k] == 0)
			continue;
		if (st[i] < a[i][k])
			return 0;
		tt = (st[i] - a[i][k]) % b[i][k];
		if (tt != 0)
			return 0;
		ans[k] = (st[i] - a[i][k]) / b[i][k];
	}
	return 1;
}
bool deal()
{
	int i, j, k, t, tt;
	if (num == 1)
	{
		for (i = 1; i <= n; i++)
			if (b[1][i] == 0)
				break;
		if (i > n)
			i--;
		if (b[1][i] != 0)
		{
			modd = b[1][1];
			rem = a[1][1];
			for (i = 2; i <= n; i++)
			{
				d = gcd(modd, b[1][i]);
				if ((rem - a[1][i]) % d != 0)
					return 0;
				if (a[1][i] == b[1][i])
					while (rem % b[1][i] != 0)
						rem += modd;
				else
					while (rem % b[1][i] != a[1][i])
						rem += modd;
				modd = modd * b[1][i] / d;
			}
			ANS = rem;
			for (i = 1; i <= n; i++)
				while (ANS < a[1][i])
					ANS += modd;
			printf("%lld\n", pow(p[1], ANS));
			flag = 1;
			return 1;
		}
	}
	for (i = 1; i <= num; i++)
	{
		for (j = 1; j <= n; j++) //p[i]:a[j]+b[j]*k,k>=0
			if (b[i][j] == 0)
				break;
		if (j <= n && b[i][j] == 0) //p[i]:a[j]
		{
			ans[j] = -1;
			for (k = 1; i < j; i++)
			{
				if (a[i][j] < a[i][k])
					return 0;
				tt = (a[i][j] - a[i][k]) % b[i][k];
				if (tt != 0)
					return 0;
				ans[k] = (a[i][j] - a[i][k]) / b[i][k];
			}
			for (k = j + 1; k <= n; k++)
			{
				if (a[i][j] < a[i][k])
					return 0;
				if (b[i][k] == 0 && a[i][k] != a[i][j])
					return 0;
				if (b[i][k] == 0)
				{
					ans[k] = -1;
					continue;
				}
				tt = (a[i][j] - a[i][k]) % b[i][k];
				if (tt != 0)
					return 0;
				ans[k] = (a[i][j] - a[i][k]) / b[i][k];
			}
			return check();
		}
	}
	for (j = 1; j < num; j++)
		for (int jj = j + 1; jj <= num; jj++)
			for (i = 1; i < n; i++)
				for (int ii = i + 1; ii <= n; ii++)
				{
					tt = (a[j][ii] - a[j][i]) * b[jj][ii] - (a[jj][ii] - a[jj][i]) * b[j][ii];
					t = b[j][i] * b[jj][ii] - b[jj][i] * b[j][ii];
					if (t == 0 && tt != 0)
						return 0;
					if (t != 0)
					{
						if (tt % t != 0)
							return 0;
						ans[i] = tt / t;
						if (ans[i] < 0)
							return 0;
						return check();
					}
				}
	modd = b[1][1];
	rem = a[1][1];
	for (i = 2; i <= n; i++)
	{
		d = gcd(modd, b[1][i]);
		if ((rem - a[1][i]) % d != 0)
			return 0;
		if (a[1][i] == b[1][i])
			while (rem % b[1][i] != 0)
				rem += modd;
		else
			while (rem % b[1][i] != a[1][i])
				rem += modd;
		modd = modd * b[1][i] / d;
	}
	ANS = rem;
	for (i = 1; i <= n; i++)
		while (ANS < a[1][i])
			ANS += modd;
	for (i = 1; i <= n; i++)
		ans[i] = (ANS - a[1][i]) / b[1][i];
	print();
	flag = 1;
	return 1;
}
int main()
{
	int i, nn;
	bool t, tt = 1;
	scanf("%d", &n);
	find_prime();
	for (i = 1; i <= n; i++)
		scanf("%d%d", &aa[i], &bb[i]);
	for (i = 1; i < n; i++)
		if (aa[i] != aa[i + 1])
		{
			tt = 0;
			break;
		}
	if (tt)
	{
		printf("%d\n", aa[1]);
		return 0;
	}
	factor(aa[1], bb[1]);
	nn = n;
	for (i = 2; i <= nn; i++)
	{
		if (aa[i] == aa[i - 1] && bb[i] == bb[i - 1])
		{
			n--;
			continue;
		}
		factoring1(i, aa[i]);
		factoring2(i, bb[i]);
		if (aa[i] > 1 || bb[i] > 1)
		{
			printf("-1\n");
			return 0;
		}
		//p[i]:a[i]+b[i]*k,k>=0
	}
	if (n == 1)
	{
		printf("%d\n", aa);
		return 0;
	}
	t = deal();
	if (flag)
		return 0;
	if (!t)
	{
		printf("-1\n");
		return 0;
	}
	else
		print();
	return 0;
}