#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#define fo(i, a, b) for (int i = a, E = b; i <= E; i++)
#define fd(i, a, b) for (int i = b, E = a; i >= E; i--)
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define ll long long
using namespace std;
const int mo = 1e9 + 7;
ll r, p[4], pp, x, y, an, ys;
int fx[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}, w[102][102], ws;
int po[10005][2], xx, yy;
int f[7850][7850];
ll ksm(ll x, int y)
{
    ll t = 1;
    for (; y; y >>= 1, x = x * x % mo)
        if (y & 1)
            t = t * x % mo;
    return t;
}
int main()
{
    //	freopen("a.in","r",stdin);
    scanf("%lld", &r);
    fo(i, 0, 3) scanf("%lld", &p[i]), pp += p[i];
    pp = ksm(pp, mo - 2);
    fo(i, 0, 3) p[i] = p[i] * pp % mo;
    fo(i, -r, r) fo(j, -r, r) if (i * i + j * j <= r * r) w[i + 51][j + 51] = ++ws, po[ws][0] = i + 51, po[ws][1] = j + 51;
    fo(i, 1, ws)
    {
        x = po[i][0];
        y = po[i][1];
        f[i][0] = 1;
        f[i][i] = -1;
        fo(j, 0, 3)
        {
            xx = x + fx[j][0];
            yy = y + fx[j][1];
            if (w[xx][yy])
                f[i][w[xx][yy]] = p[j];
        }
    }
    fo(i, 1, ws)
    {
        x = ksm(f[i][i], mo - 2);
        fo(j, i + 1, min(ws, i + 2 * r))
        {
            ys = f[j][i] * x % mo;
            if (ys)
            {
                f[j][0] = (f[j][0] - f[i][0] * ys) % mo;
                fo(k, i, min(ws, i + 2 * r)) f[j][k] = (f[j][k] - f[i][k] * ys) % mo;
            }
        }
    }
    fd(i, w[51][51], ws)
    {
        an = -f[i][0] * ksm(f[i][i], mo - 2) % mo;
        fd(j, max(i - r * 2, w[51][51]), i - 1)
            f[j][0] = (f[j][0] + f[j][i] * an) % mo;
    }
    printf("%lld\n", (an + mo) % mo);
}

// -------------

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, a, n) for (int i = a; i < n; i++)
// #define per(i, a, n) for (int i = n - 1; i >= a; i--)
// typedef long long ll;
// const ll mod = 1000000007;
// ll powmod(ll a, ll b)
// {
//     ll res = 1;
//     a %= mod;
//     assert(b >= 0);
//     for (; b; b >>= 1)
//     {
//         if (b & 1)
//             res = res * a % mod;
//         a = a * a % mod;
//     }
//     return res;
// }

// const int W = 105;
// int R, id[110][110], tot, pr[11111];
// ll a[10], f[11111][222], g[11111];
// int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
// ll gao()
// {
//     rep(i, 0, tot) pr[i] = i;
//     rep(i, 0, tot)
//     {
//         // rep(j,0,W) if (f[i][W+j]) {
//         // if (j==0) break;
//         // swap(pr[i],pr[i+j]);
//         // for (int k=i;k<=i+W&&k<tot;k++)
//         // swap(f[k][W+j-(k-i)],f[k][W-(k-i)]);
//         // break;
//         // }
//         if (f[i][W] == 0)
//             continue;
//         ll inv = powmod(f[i][W], mod - 2);
//         rep(j, 0, W) f[i][W + j] = f[i][W + j] * inv % mod;
//         g[i] = g[i] * inv % mod;
//         for (int k = i + 1; k <= i + W && k < tot; k++)
//             if (f[k][W - (k - i)])
//             {
//                 ll c = (mod - f[k][W - (k - i)]) % mod;
//                 rep(j, 0, W)(f[k][W - (k - i) + j] += c * f[i][W + j]) %= mod;
//                 (g[k] += c * g[i]) %= mod;
//             }
//     }
//     per(i, 0, tot) if (f[i][W] != 0)
//     {
//         for (int k = i - 1; k >= i - W && k > 0; k--)
//             if (f[k][W + (i - k)])
//                 (g[k] -= f[k][W + (i - k)] * g[i]) %= mod;
//         if (pr[i] == id[R][R])
//             return g[i];
//     }
//     return 0;
// }
// int main()
// {
//     scanf("%d%lld%lld%lld%lld", &R, &a[0], &a[1], &a[2], &a[3]);
//     ll p = powmod(a[0] + a[1] + a[2] + a[3], mod - 2);
//     rep(i, 0, 4) a[i] = a[i] * p % mod;
//     for (int i = -R; i <= R; i++)
//         for (int j = -R; j <= R; j++)
//         {
//             if (i * i + j * j <= R * R)
//                 id[i + R][j + R] = tot++;
//             else
//                 id[i + R][j + R] = -1;
//         }
//     for (int i = -R; i <= R; i++)
//         for (int j = -R; j <= R; j++)
//             if (i * i + j * j <= R * R)
//             {
//                 int d = id[i + R][j + R];
//                 f[d][W] = 1;
//                 g[d] = 1;
//                 rep(dd, 0, 4)
//                 {
//                     int x = i + dx[dd], y = j + dy[dd];
//                     if (x * x + y * y <= R * R)
//                         f[d][W - d + id[x + R][y + R]] = mod - a[dd];
//                 }
//             }
//     ll w = gao();
//     if (w < 0)
//         w += mod;
//     printf("%lld\n", w);
// }