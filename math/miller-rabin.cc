/* Miller-Rabin Prime Test, by Abreto<m@abreto.net>. */

namespace miller_rabin {

typedef long long int ll;

inline ll add(const ll a, const ll b, const ll mod)
{
    ll z = a + b;
    if (z >= mod) z -= mod;
    return z;
}
inline ll mul(ll a, ll b, const ll mod)
{
    ll z = 0;
    if (a >= mod) a %= mod;
    if (b >= mod) b %= mod;
    while (b)
    {
        if (1 & b) z = add(z, a, mod);
        a = add(a, a, mod);
        b >>= 1;
    }
    return z;
}

ll qow(ll a, ll x, ll mod)
{
    ll ret = 1ll;
    while (x)
    {
        if (1 & x) ret = mul(ret, a, mod);
        a = mul(a, a, mod);
        x >>= 1;
    }
    return ret;
}

const int K = 5;
const int p[] = {
    2, 3, 7, 61, 24251
};
const ll strong = 46856248255981ll;
/* 46 856 248 255 981 in (0, 1e16) */

bool mr(ll n, int k)
{
    ll d = n - 1;
    int s = 0;
    while (d > 1 && 0 == (d & 1))
    {
        s++;
        d >>= 1;
    }
    for (int i = 0; i < k; i++)
    {
        ll a = (i < K) ? p[i] : (1 + rand() % (n - 1));
        ll x = qow(a, d, n);
        for (int j = 0; j < s; j++)
        {
            ll xp = mul(x, x, n);
            if (1 == xp && x != 1 && x != n-1) return false;
            x = xp;
        }
        if (x != 1) return false;
    }
    return true;
}

/* 2,3,5,7,11,13 */
const int pre[] = {3, 5, 7, 11, 13};
bool test(ll n, int k = 5)
{
    if (2 == n) return true;
    if (0 == (n & 1)) return false;
    if (strong == n) return false;
    for (int i = 0; i < 5; i++)
    {
        if (n == pre[i]) return true;
        if (n == n / pre[i] * pre[i])
            return false;
    }
    return mr(n, k);
}

}
