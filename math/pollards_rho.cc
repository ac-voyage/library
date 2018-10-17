/* Pollard's rho, by Abreto<m@abreto.net>. */

namespace pollards_rho {

typedef long long int ll;

inline ll add(const ll a, const ll b, ll mod)
{
    ll z = a + b;
    if (z >= mod) z -= mod;
    return z;
}
inline ll mul(ll a, ll b, ll mod)
{
    ll z = 0ll;
    if (a >= mod) a -= a / mod * mod;
    if (b >= mod) b -= b / mod * mod;
    while (b)
    {
        if (1 & b) z = add(z, a, mod);
        a = add(a, a, mod);
        b >>= 1;
    }
    return z;
}

ll gcd(ll m, ll n) { return (0 == n) ? m : gcd(n, m % n); }

ll find(ll n, int c = -1)
{
    ll x = rand() % n;
    ll y = x, k = 2;
    for (int i = 2; ; i++)
    {
        x = add(mul(x, x, n), n - 1, n);
        ll d = gcd( abs(y - x) , n );
        if (1 != d && n != d) return d;
        if (i == k)
        {
            y = x;
            k <<= 1;
        }
    }
}

/** usage:
 * void find(ll n, int c = 107)
 * {
 *   if (1 == n) return;
 *   if ( miller-rabin(n) )
 *   {
 *     n is a prime;
 *     return;
 *   }
 *   ll p = n, k = c;
 *   while (p >= n) p = pollards_rho(p, k--);
 *   find(p, c);
 *   find(n/p, c);
 * }
 **/

}
