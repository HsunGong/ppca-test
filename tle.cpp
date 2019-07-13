#include<cstdio>
#include<algorithm>
using namespace std;
 
const int maxn = 1 << 12;
 
int a[maxn];
int b[maxn];
int p[maxn], q[maxn];
int rp[maxn], rq[maxn];
int k;
 
int main() {
	scanf("%d", &k);
	int n = 1 << k;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum ^= a[i];
	}
	if (sum) {
		printf("Fou");
		return 0;
	}
	printf("Shi\n");
	for (int i = 1; i <= n; i++) {
		p[i] = q[i] = i - 1;
		rp[i - 1] = rq[i - 1] = i;
	}
	while (1) {
		int indi = 0;
		int indj = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				int x = (a[i] ^ b[i])&(a[j] ^ b[j]);
				if (x) {
					indi = i;
					indj = j;
					b[i] ^= x;
					b[j] ^= x;
					break;
				}
			}
			if (indi) break;
		}
		if (!indi) break;
		while (indi != indj) {
			int t = rp[b[indi] ^ q[indi]];
			rp[p[t]] = indi;
			rq[q[t]] = indj;
			rp[p[indi]] = t;
			rq[q[indj]] = t;
			swap(p[t], p[indi]);
			swap(q[t], q[indj]);
			indi = t;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", p[i]);
	}
	printf("\n");
	for (int i = 1; i <= n; i++) {
		printf("%d ", q[i]);
	}
	return 0;
}