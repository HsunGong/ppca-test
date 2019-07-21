#include <bits/stdc++.h>
using namespace std;
#define iinf 2000000000
#define linf 1000000000000000000LL
#define ulinf 10000000000000000000ull
#define MOD1 1000000007LL
#define mpr make_pair
#define FS first
#define SC second
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned long UL;
typedef unsigned short US;
typedef pair<int, int> pii;
typedef pair<int, pii> p3i;
clock_t __stt;
inline void TStart() { __stt = clock(); }
inline void TReport() { cerr << fixed << setprecision(3) << "\nCurrent Case Taken Time : " << (double)(clock() - __stt) / CLOCKS_PER_SEC << "sec\n"; }
template <typename T>
T MIN(T a, T b) { return a < b ? a : b; }
template <typename T>
T MAX(T a, T b) { return a > b ? a : b; }
template <typename T>
T ABS(T a) { return a > 0 ? a : (-a); }
template <typename T>
void UMIN(T &a, T b)
{
    if (b < a)
        a = b;
}
template <typename T>
void UMAX(T &a, T b)
{
    if (b > a)
        a = b;
}
const int MX = 7845, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int R, p[4], q[4];
int powM(int V, int T)
{
    int R = 1;
    while (T)
    {
        if (T & 1)
            R = (LL)R * (LL)V % MOD1;
        T >>= 1;
        V = (LL)V * (LL)V % MOD1;
    }
    return R;
}
int arr[MX][MX + 1], px[MX], py[MX], id[205][205], cnt, x[MX];
int main()
{
    // inputting start
    // 数据结构记得初始化！
    // 变量名不要写重写混！
    int i, j, k, s = 0;
    scanf("%d", &R);
    for (i = 0; i < 4; ++i)
    {
        scanf("%d", p + i);
        s += p[i];
    }
    for (i = 0; i < 4; ++i)
    {
        q[i] = (LL)p[i] * (LL)powM(s, MOD1 - 2ll) % MOD1;
    }
#ifdef LOCAL
    TStart();
#endif
    // calculation start
    // 数据结构记得初始化！
    // 变量名不要写重写混！
    memset(id, -1, sizeof(id));
    for (i = -100; i <= 100; ++i)
    {
        for (j = -100; j <= 100; ++j)
        {
            if (i * i + j * j <= R * R)
            {
                px[cnt] = i;
                py[cnt] = j;
                id[i + 100][j + 100] = cnt++;
            }
        }
    }
    for (i = 0; i < cnt; ++i)
    {
        int x = px[i], y = py[i];
        for (j = 0; j < 4; ++j)
        {
            int nx = x + dx[j], ny = y + dy[j];
            if (id[nx + 100][ny + 100] != -1)
            {
                arr[i][id[nx + 100][ny + 100]] = (MOD1 - q[j]) % MOD1;
            }
        }
        arr[i][i] = 1;
        arr[i][cnt] = 1;
    }
    for (i = 0; i < cnt; ++i)
    {
        for (j = i; j < cnt; ++j)
        {
            if (arr[j][i])
                break;
        }
        if (j == cnt)
            continue;
        if (j > i)
        {
            for (k = 0; k <= cnt; ++k)
            {
                swap(arr[i][k], arr[j][k]);
            }
        }
        int d;
        for (d = cnt; d >= 0 && !arr[i][d]; --d)
            ;
        for (j = i + 1; j < cnt; ++j)
        {
            if (!arr[j][i])
                continue;
            int coe = (MOD1 - (LL)arr[j][i] * (LL)powM(arr[i][i], MOD1 - 2ll) % MOD1) % MOD1;
            for (k = i; k <= d; ++k)
            {
                arr[j][k] += (LL)coe * (LL)arr[i][k] % MOD1;
                if (arr[j][k] >= MOD1)
                    arr[j][k] -= MOD1;
            }
        }
    }
    for (i = cnt - 1; i >= 0; --i)
    {
        for (k = cnt - 1; k > i; --k)
        {
            arr[i][cnt] += MOD1 - (LL)arr[i][k] * (LL)x[k] % MOD1;
            if (arr[i][cnt] >= MOD1)
                arr[i][cnt] -= MOD1;
        }
        x[i] = (LL)arr[i][cnt] * (LL)powM(arr[i][i], MOD1 - 2ll) % MOD1;
    }
    printf("%d\n", x[id[100][100]]);
#ifdef LOCAL
    TReport();
#endif
    return 0;
}