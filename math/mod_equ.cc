#include <cstdio>
#include <cassert>
#include <cstdlib>

using namespace std;

class mod_equ_resolver
{
    typedef long long int ll;
    ll a, m;
    inline void gurantee(void)
    {
        if(a < 0)
        {
            ll k = (-a) / m;
            a += (k+1ll) * m;
            a = (a + m) % m;
        } else {
            a %= m;
        }
        // printf("x = %lld (mod %lld)\n",a, m);
    }
public:
    mod_equ_resolver(void)
    {
        a = 0ll;
        m = 1ll;
    }
    ll exgcd(ll m, ll n, ll &x, ll &y)
    {
        if(0 == n)
        {
            x = 1;
            y = 0;
            return m;
        }
        ll g = exgcd(n, m%n, x, y);
        ll t = x;
        x = y;
        y = t - m / n * y;
        return g;
    }
    int onemore(ll a2, ll m2)
    {
        ll x, y;
        ll g = exgcd(m, m2, x, y);
        assert(x*m+y*m2==g);
        a2 = (a2 + m2) % m2;
        if (abs(a2-a) % g) return -1;
        ll newm = m / g * m2;
        ll newa = a + (a2-a) / g * x * m;
        a = newa;
        m = newm;
        gurantee();
        return 0;
    }
    ll resolve(void)
    {
        return a;
    }
};
