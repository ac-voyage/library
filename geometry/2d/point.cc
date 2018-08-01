/* 2D Point Class, by Abreto<m@abreto.net> */
#include <cmath>

using namespace std;

template <typename T>
struct point
{
    T x,y;
    point(void):x(T()),y(T()){}
    point(T xx, T yy):x(xx),y(yy){}
    inline point operator-(void) const {return point(-x,-y);}
    inline point operator+(const point& b) const {return point(x+b.x,y+b.y);}
    inline point operator-(const point& b) const {return point(x-b.x,y-b.y);}
    inline point operator->*(const point &b) const { return (b-(*this)); }
    inline T operator*(const point& b) const {return ((x)*(b.x))+((y)*(b.y));} /* inner product */
    inline T operator^(const point& b) const {return ((x)*(b.y))-((b.x)*(y));} /* outter product */
    inline point& operator+=(const point& b) {point tmp=(*this)+b;(*this)=tmp;return (*this);}
    inline point& operator-=(const point& b) {point tmp=(*this)-b;(*this)=tmp;return (*this);}
    inline bool operator==(const point& b) const {return (x==b.x)&&(y==b.y);}
    inline bool operator!=(const point& b) const {return !((*this)==b);}
};

#define vec point
