
#include <bitset>
#include <vector>
template <int MAXN>
struct abprimes_euler
{
    std::bitset<MAXN> notprime;
    std::vector<int> primes;
    abprimes_euler(void)
    {
        for(int i = 2;i < MAXN;i++)
        {
            if( !notprime.test(i) )
                primes.push_back(i);
            for(auto p : primes)
            {
                if (i * p >= MAXN)
                    break;
                notprime[i * p] = 1;
                if (0 == i % p)
                    break;
            }
        }
    }
};
