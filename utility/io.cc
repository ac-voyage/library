#include <cstdio>

using namespace std;

class abio
{
    static const unsigned BUF_SZ = 65535;
    FILE *istream, *ostream;
    char ibuf[BUF_SZ], obuf[BUF_SZ];
    size_t ip, isz;
    size_t op, osz;
    inline void clear_ibuf(void)
    {
        ip = isz = 0u;
    }
    inline void clear_obuf(void)
    {
        op = osz = 0u;
    }
    inline void clear_buffer(void)
    {
        clear_ibuf();
        clear_obuf();
    }
    inline size_t read_buffer(void)
    {
        isz = fread(ibuf, sizeof(char), BUF_SZ, istream);
        ip = 0;
        return isz;
    }
    inline size_t write_buffer(void)
    {
        if(osz)
        {
            size_t ret = fwrite(obuf+op, sizeof(char), osz-op, ostream);
            op += ret;
            if(op == osz) clear_obuf();
            return ret;
        }
        return 0;
    }
public:
    abio(FILE *input = stdin, FILE *output = stdout)
    {
        this->istream = input;
        this->ostream = output;
        clear_buffer();
    }
    abio(const char *input, const char *output)
    {
        this->istream = fopen(input, "r");
        this->istream = fopen(output, "w+");
        clear_buffer();
    }
    ~abio(void)
    {
        write_buffer();
        fclose(istream);
        fclose(ostream);
    }
    inline int getchar(void)
    {
        if(0 == isz || isz == ip) read_buffer();
        if(0 == isz || isz == ip) return EOF;
        return ibuf[ip++];
    }
    inline int putchar(int ch)
    {
        if(osz == BUF_SZ) write_buffer();
        if(osz == BUF_SZ) return EOF;
        return (obuf[osz++] = ch);
    }
    inline int read_int(int &x)
    {
        int flag = 0, ch;
        x = 0;
        while((EOF!=(ch=getchar()))&&(('-'!=ch)&&((ch<'0')||(ch>'9'))));
        if(EOF==ch) return EOF;
        if('-'==ch){flag=1;ch=getchar();}
        if(EOF==ch) return EOF;
        for(;(((ch>='0')&&(ch<='9')));ch=getchar()){x*=10;x+=(ch-'0');}
        if(flag)x*=(-1);
        return 1;
    }
    inline long long int read_ll(long long int &x)
    {
        int flag = 0, ch;
        x = 0ll;
        while((EOF!=(ch=getchar()))&&(('-'!=ch)&&((ch<'0')||(ch>'9'))));
        if(EOF==ch) return EOF;
        if('-'==ch){flag=1;ch=getchar();}
        if(EOF==ch) return EOF;
        for(;(((ch>='0')&&(ch<='9')));ch=getchar()){x*=(10ll);x+=(ch-'0');}
        if(flag)x*=(-1ll);
        return 1;
    }
    inline void write_ll(long long int x, char append = 0)
    {
        int d[20],nd=0;
        if(0==x) putchar('0');
        if(x<0){putchar('-');x=-x;}
        while(x){d[nd++]=x%10;x/=10;}
        while(nd--)putchar('0'+d[nd]);
        if(append)putchar(append);
    }
};
