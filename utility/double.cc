/* Double Class, by Abreto<m@abreto.net>. */

#define eps (1e-9)
template < typename T = double >
struct dbl
{
    T x;
    dbl(void):x(0.0){}
    template <typename U>
    dbl(U a):x((T)a){}
    inline char sgn(void){return ((x>=-eps)&&(x<=eps))?(0):((x>eps)?(1):(-1));}
    inline T tabs(void){return ((x>=-eps)&&(x<=eps))?(0.0):((x>eps)?(x):(-x));}
    inline dbl abs(void){return dbl(tabs());}
    template <typename U> inline dbl &operator=(const U b) {x=(T)b;return (*this);}
    inline T *operator&(void) {return &x;}
    inline dbl operator-(void) const {return dbl(-x);}
    inline dbl operator+(const dbl &b) const {return dbl(x+b.x);}
    inline dbl operator-(const dbl &b) const {return dbl(x-b.x);}
    inline dbl operator*(const dbl &b) const {return dbl(x*b.x);}
    inline dbl operator/(const dbl &b) const {return dbl(x/b.x);}
    template <typename U> inline dbl operator^(const U &b) const {T ret=1.0,base=x;while(b){if(b&1)ret*=base;base*=base;b>>=1;}return dbl(ret);}
    inline dbl operator+=(const dbl &b) {return dbl(x+=b.x);}
    inline dbl operator-=(const dbl &b) {return dbl(x-=b.x);}
    inline dbl operator*=(const dbl &b) {return dbl(x*=b.x);}
    inline dbl operator/=(const dbl &b) {return dbl(x/=b.x);}
    template <typename U> inline dbl operator^=(const U &b) {dbl tmp=(*this)^b;*this=tmp;return tmp;}
    inline bool operator==(const dbl &b) const {return (0 == ((*this)-b).sgn());}
    inline bool operator!=(const dbl &b) const {return (0 != ((*this)-b).sgn());}
    inline bool operator<(const dbl &b) const {return (-1 == ((*this)-b).sgn());}
    inline bool operator<=(const dbl &b) const {return (((*this)==b) || ((*this)<b));}
    inline bool operator>(const dbl &b) const {return (b < (*this));}
    inline bool operator>=(const dbl &b) const {return (((*this)==b) || ((*this)>b));}
    template <typename U> inline operator U() const {return (U)x;}
    inline char operator[](unsigned n) {if(n >= 0){long long int ret=x;while(n--){ret/=10;}return (ret%10);}else{T ret=x;n=-n;while(n--)ret*=10.0;return ((long long int)ret)%10;}}
};

typedef dbl<> Double;
