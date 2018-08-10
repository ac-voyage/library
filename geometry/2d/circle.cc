/* 2D Circle Base Class, by Abreto<m@abreto.net>. */

/* requirement: point.cc */
#include "point.cc"

#include <utility>

namespace ab_geometry_2d {

using namespace std;

struct circle
{
    point o;
    T r;
    circle(void) : r(T()) {}
    circle(point center, T radius) : o(center), r(radius) {}

    inline ab_float arclen(ab_float theta)
    {
        return theta * r;
    }
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
    relation_t with(const circle &C) const
    {
        T dis2 = (o->*(C.o)).norm2();
        T dr2 = sqr(r - C.r), rs2 = sqr(r + C.r);
        if ( 0 == sgn(dis2) && 0 == sgn(dr2) ) return same;
        if ( -1 == sgn(dis2 - dr2) ) return contain;
        if ( 0 == sgn(dis2 - dr2) ) return intouch;
        if ( -1 == sgn(dr2 - dis2) && -1 == sgn(dis2 - rs2) ) return intersect;
        if ( 0 == sgn(dis2 - rs2) ) return outtouch;
        if ( -1 == sgn(rs2 - dis2) ) return separate;
        return unknow_relation;
    }

    enum point_relation_t {
        in = 0x001,
        on = 0x010,
        out = 0x100,
        unknow_point_relation = 0xfff
    };
    point_relation_t with(const point &P) const
    {
        T dis2 = (o->*P).norm2();
        T r2 = sqr(r);
        int type = sgn(dis2 - r2);
        if (-1 == type) return in;
        if ( 0 == type) return on;
        if (+1 == type) return out;
        return unknow_point_relation;
    }

    ab_float central_angle(const point &A, const point &B, const bool reflex = false) const
    {
        T dot = (A * B);
        if (0 == sgn(dot)) return 1. * (A != B) * pi;
        ab_float angle = ((ab_float)(dot)) / r / r;
        if ( reflex ) angle = 2. * pi - angle;
        return angle;
    }

    /* be sure (*this) intersect with C */
    pair<point,point> crosspoint(const circle &C) const
    {
        ab_float d = (o ->* (C.o)).norm();
        // TODO:
    }
};

}
