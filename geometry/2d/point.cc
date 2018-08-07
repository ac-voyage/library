/* 2D Point Class, by Abreto<m@abreto.net> */
#include <cmath>

/**
 * Define ABG2d_USE_LL if you want to use long long int for cordnates.
 */

namespace ab_geometry_2d {

using namespace std;

typedef double ab_float;

const ab_float pi = acos(-1.);

#ifdef ABG2d_USE_LL
typedef long long int T;
#else
typedef ab_float T;
const ab_float eps = 1e-8;
#endif

inline T myabs(T x)
{
    if(x < 0) return (-x);
    return x;
}

inline int sgn(T x)
{
    /* no ``difference'' in fact */
#ifdef ABG2d_USE_LL
    if (0 == x) return 0;
#else
    if (myabs(x) < eps) return 0;
#endif
    return (x > 0) ? 1 : -1;
}

inline T sqr(T x)
{
    return (x * x);
}

struct point
{
    T x,y;
    point(void):x(T()),y(T()){}
    point(T xx, T yy):x(xx),y(yy){}
    inline T norm2(void) { return sqr(x) + sqr(y); }
    inline ab_float norm(void) { return sqrt((ab_float)(norm2())); }
    inline point operator-(void) const {return point(-x,-y);}
    inline point operator+(const point& b) const {return point(x+b.x,y+b.y);}
    inline point operator-(const point& b) const {return point(x-b.x,y-b.y);}
    inline point operator->*(const point &b) const { return (b-(*this)); }
    inline T operator*(const point& b) const {return ((x)*(b.x))+((y)*(b.y));} /* inner product */
    inline T operator^(const point& b) const {return ((x)*(b.y))-((b.x)*(y));} /* outter product */
    inline point& operator+=(const point& b) {point tmp=(*this)+b;(*this)=tmp;return (*this);}
    inline point& operator-=(const point& b) {point tmp=(*this)-b;(*this)=tmp;return (*this);}
    inline bool operator==(const point& b) const {return (0==sgn(x-b.x))&&(0==sgn(y-b.y));}
    inline bool operator!=(const point& b) const {return !((*this)==b);}
    inline point operator<<(const ab_float& theta) const { ab_float ct = cos(theta), st = sin(theta); return point(ct*x - st*y, st*x + ct*y); } /* rotate counter-clockwise in radian */
};

typedef point vec;


}   // namespace `ab_geometry_2d`
