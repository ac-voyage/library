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

    inline ab_float circumference(void)
    {
        return 2. * pi * r;
    }
    inline ab_float area(void)
    {
        return pi * r * r;
    }

    /* bool contain(const circle &C, const bool including_touch = false) const
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
    } */
    enum relation_t {
      same = 0x00000,
      contain = 0x00001,
      intouch = 0x00010,
      intersect = 0x00100,
      outtouch = 0x01000,
      separate = 0x10000,
      unknow_relation = 0xfffff
    };
    relation_t with(const circle &C)
    {
        T dis2 = (o->*(C.o)).norm2();
        T dr2 = sqr(r - C.r), rs2 = sqr(r + C.r);
        if ( 0 == sgn(dis2) && 0 == sgn(dr2) ) return same;
        if ( dis2 < dr2 ) return contain;
        if ( dis2 == dr2 ) return intouch;
        if ( dr2 < dis2 && dis2 < rs2 ) return intersect;
        if ( dis2 == rs2 ) return outtouch;
        if ( rs2 < dis2 ) return separate;
        return unknow_relation;
    }
};

}
