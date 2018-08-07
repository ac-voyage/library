/* 2D Circle Base Class, by Abreto<m@abreto.net>. */

/* requirement: point.cc */
#include "point.cc"

namespace ab_geometry_2d {

using namespace std;

struct circle
{
    point o;
    T r;
    circle(void) : r(T()) {}
    circle(point center, T radius) : o(center), r(radius) {}

    bool contain(const circle &C, const bool including_touch = false) const
    {
        T dis2 = (o->*(C.o)).norm2();
        T raw_diff = r - C.r;
        if ( -1 == sgn(raw_diff) ) return false;
        T dr2 = sqr(raw_diff);
        return (dis2 < dr2) || (including_touch && (dis2 == dr2));
    }
    inline bool in(const circle &C, const bool including_touch = false) const
    {
      return C.contain(*this, including_touch);
    }
};

}
