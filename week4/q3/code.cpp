#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define sz(a) static_cast<int>(a.size())
#define all(a) a.begin(), a.end()
#define repn(i, n) for (int i = 0; i < int(n); ++i)
#define fi first
#define se second
#define pb push_back
typedef long long LL;
typedef pair<LL, LL> PL;
typedef vector<LL> VL;
typedef pair<VL, VL> PVL;

struct Space
{
    char t;
    LL i = 0, j = 0, di = 0, dj = 0;
    Space() {}
    Space(char _t) : t(_t) {}
    Space(LL _i, LL _j, LL _di, LL _dj) : t('s'), i(_i), j(_j), di(_di), dj(_dj) {}
    bool single() const { return di == 0 && dj == 0; }
    bool contains(LL x, LL y) const
    {
        if (t == 'n')
            return false;
        if (t == 'a')
            return x >= 0 && y >= 0;
        x -= i, y -= j;
        if (x < 0 || y < 0)
            return false;
        if (di == 0 && dj == 0)
            return x == 0 && y == 0;
        if (di == 0)
            return x == 0 && y % dj == 0;
        if (dj == 0)
            return y == 0 && x % di == 0;
        return x % di == 0 && y % dj == 0 && x / di == y / dj;
    }
};
const Space kNone('n');
const Space kAll('a');

LL ext_gcd(LL a, LL b, LL *x, LL *y)
{
    if (b == 0)
    {
        *x = 1, *y = 0;
        return a;
    }
    LL u, v, g = ext_gcd(b, a % b, &u, &v);
    *x = v, *y = u - a / b * v;
    return g;
}

Space solve(LL a1, LL b1, LL a2, LL b2)
{
    if (b1 == 0 && b2 == 0)
        return a1 == a2 ? kAll : kNone;
    if (b1 == 0)
    {
        LL j = (a1 - a2) / b2;
        return j >= 0 && a1 == a2 + b2 * j ? Space(0, 1, j, 0) : kNone;
    }
    if (b2 == 0)
    {
        LL i = (a2 - a1) / b1;
        return i >= 0 && a2 == a1 + b1 * i ? Space(i, 0, 0, 1) : kNone;
    }
    LL i, j, g = ext_gcd(b1, -b2, &i, &j);
    if ((a2 - a1) % g != 0)
        return kNone;
    LL t = (a2 - a1) / g;
    i *= t, j *= t;
    LL di = b2 / abs(g), dj = b1 / abs(g);
    auto adjust = [&i, &j, di, dj](LL k) { i += di * k, j += dj * k; };
    if (i < 0)
        adjust((-i + di - 1) / di);
    if (j < 0)
        adjust((-j + dj - 1) / dj);
    adjust(-min(i / di, j / dj));
    return Space(i, j, di, dj);
}

Space intersect(Space a, Space b)
{
    if (a.t == 'n' || b.t == 'n')
        return kNone;
    if (a.t == 'a')
        return b;
    if (b.t == 'a')
        return a;
    if (a.single())
        return b.contains(a.i, a.j) ? a : kNone;
    if (b.single())
        return a.contains(b.i, b.j) ? b : kNone;
    auto cross = [](LL x1, LL y1, LL x2, LL y2) {
        return x1 * y2 - x2 * y1;
    };
    LL t = cross(a.di, a.dj, b.di, b.dj);
    if (t == 0)
    {
        if (cross(a.di, a.dj, a.i - b.i, a.j - b.j) != 0)
            return kNone;
        Space r = solve(a.i + a.j, a.di + a.dj, b.i + b.j, b.di + b.dj);
        if (r.t == 'n')
            return kNone;
        if (r.t == 'a')
            return a;
        LL i = a.i + a.di * r.i, di = a.di * r.di;
        LL j = a.j + a.dj * r.i, dj = a.dj * r.di;
        return Space(i, j, di, dj);
    }
    else
    {
        LL c1 = cross(a.di, a.dj, a.i, a.j);
        LL c2 = cross(b.di, b.dj, b.i, b.j);
        LL x = (b.di * c1 - a.di * c2) / t;
        LL y = (b.dj * c1 - a.dj * c2) / t;
        return a.contains(x, y) && b.contains(x, y) ? Space(x, y, 0, 0) : kNone;
    }
}

bool intersect(PVL a, PVL b, PVL *c)
{
    Space r = kAll;
    repn(i, sz(a.fi))
    {
        r = intersect(r, solve(a.fi[i], a.se[i], b.fi[i], b.se[i]));
    }
    if (r.t == 'n')
        return false;
    if (r.t == 'a')
    {
        *c = a;
        return true;
    }
    repn(i, sz(a.fi))
    {
        c->fi.pb(a.fi[i] + a.se[i] * r.i);
        c->se.pb(a.se[i] * r.di);
    }
    return true;
}

int run()
{
    int n;
    cin >> n;
    // printf("Size=%d, ", n);
    VL va(n), vb(n);
    repn(i, n) cin >> va[i] >> vb[i];
    VL ps;
    auto append_primes = [&ps](LL x) {
        for (LL y = 2; y * y <= x; ++y)
            if (x % y == 0)
            {
                ps.pb(y);
                while (x % y == 0)
                    x /= y;
            }
        if (x > 1)
            ps.pb(x);
    };
    repn(i, n)
    {
        append_primes(va[i]);
        append_primes(vb[i]);
    }
    sort(all(ps));
    ps.erase(unique(all(ps)), ps.end());
    auto to_vec = [&ps](LL x) {
        VL r;
        for (LL p : ps)
        {
            r.pb(0);
            while (x % p == 0)
                ++r.back(), x /= p;
        }
        return r;
    };
    vector<PVL> es;
    repn(i, n) es.emplace_back(to_vec(va[i]), to_vec(vb[i]));
    PVL r = es[0];
    repn(i, n)
    {
        PVL tmp;
        if (!intersect(r, es[i], &tmp))
        {
            cout << -1 << endl;
            return 0;
        }
        r = tmp;
    }
    const LL MOD = LL(1e9) + 7;
    auto pow = [&MOD](LL a, LL b) {
        LL c = 1;
        a %= MOD;
        for (; b > 0; b >>= 1, a = a * a % MOD)
            if (b & 1)
                c = c * a % MOD;
        return c;
    };
    LL ans = 1;
    repn(i, sz(ps)) ans = ans * pow(ps[i], r.fi[i]) % MOD;
    cout << ans << endl;
    return 0;
}

int main()
{
    // run();
    int cnt = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++){
        run();
    }
}