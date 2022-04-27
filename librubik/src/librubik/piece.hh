#pragma once
#include <algorithm>
#include <array>
#include <sstream>
#include <string>
#include <variant>

#include "color.hh"
#include "matrix3D.hh"
#include "move.hh"
#include "vector3D.hh"

namespace rubik
{
    class Piece
    {
    public:
        Vector3D<int> coords;
        Vector3D<Color> colors;

        friend std::ostream& operator<<(std::ostream& os, const Piece& p);

        enum Type
        {
            NONE,
            CENTER,
            EDGE,
            CORNER

        };

        Piece::Type get_type();

        bool operator==(const Piece& p)
        {
            return (coords == p.coords && colors == p.colors);
        }
        bool operator!=(const Piece& p)
        {
            return (coords != p.coords || colors != p.colors);
        }

        bool operator<(const Piece& p)
        {
            return coords.x < p.coords.x
                ? true
                : coords.y < p.coords.y ? true : coords.z < p.coords.z;
        }
        bool operator>(const Piece& p)
        {
            return coords.x > p.coords.x
                ? true
                : (coords.y > p.coords.y ? true : coords.z > p.coords.z);
        }

        bool operator<=(const Piece& p)
        {
            return (coords.x <= p.coords.x && coords.y <= p.coords.y);
        }
        bool operator>=(const Piece& p)
        {
            return (coords.x <= p.coords.x && coords.y <= p.coords.y);
        }

        void do_move(Face face, Direction dir);
        void do_move(Axis axis, Direction dir);
    };

    // FIXME

} // namespace rubik
