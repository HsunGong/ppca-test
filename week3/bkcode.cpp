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
	for (int i = 1; i < n; i++) {
		int indi = i;
		int indj = i + 1;
		b[indj] ^= a[indi] ^ b[indi];
		b[indi] = a[indi];
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