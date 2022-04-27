#include "piece.hh"

#include "color.hh"
#include "vector3D.hh"

namespace rubik
{
    std::ostream& operator<<(std::ostream& os, const Piece& p)
    {
        return os << p.coords << " " << p.colors;
    }

    Piece::Type Piece::get_type()
    {
        int faces = 0;
        if (colors.x != Color::NONE)
        {
            faces++;
        }
        if (colors.y != Color::NONE)
        {
            faces++;
        }
        if (colors.z != Color::NONE)
        {
            faces++;
        }

        switch (faces)
        {
        case 1:
            return Piece::Type::CENTER;
        case 2:
            return Piece::Type::EDGE;
        case 3:
            return Piece::Type::CORNER;
        default:
            return Piece::Type::NONE;
        }
    }

    void Piece::do_move(Face face, Direction dir)
    {
        auto rX =
            Matrix3D<int>{ { { { 1, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 } } } };

        Matrix3D<int> rY{ { { { 0, 0, 1 }, { 0, 1, 0 }, { -1, 0, 0 } } } };

        Matrix3D<int> rZ{ { { { 0, -1, 0 }, { 1, 0, 0 }, { 0, 0, 1 } } } };

        switch (face)
        {
        case UP:
            if (dir == CLOCKWISE)
            {
                rZ.transpose();
                coords = rZ * coords;
            }
            else
            {
                coords = rZ * coords;
            }
            colors = { colors.y, colors.x, colors.z };

            return;

        case DOWN:
            if (dir == CLOCKWISE)
            {
                coords = rZ * coords;
            }
            else
            {
                rZ.transpose();
                coords = rZ * coords;
            }
            colors = { colors.y, colors.x, colors.z };

            return;

        case LEFT:
            if (dir == CLOCKWISE)
            {
                coords = rY * coords;
            }
            else
            {
                rY.transpose();
                coords = rY * coords;
            }
            colors = { colors.z, colors.y, colors.x };

            return;

        case RIGHT:
            if (dir == CLOCKWISE)
            {
                rY.transpose();
                coords = rY * coords;
            }
            else
            {
                coords = rY * coords;
            }
            colors = { colors.z, colors.y, colors.x };

            return;

        case FRONT:
            if (dir == CLOCKWISE)
            {
                rX.transpose();
                coords = rX * coords;
            }
            else
            {
                coords = rX * coords;
            }
            return;

        case BACK:
            if (dir == CLOCKWISE)
            {
                coords = rX * coords;
            }
            else
            {
                rX.transpose();
                coords = rX * coords;
            }
            return;
        }
    }

    void Piece::do_move(Axis axis, Direction dir)
    {
        switch (axis)
        {
        case X:
            do_move(RIGHT, dir);
            break;

        case Y:
            do_move(UP, dir);
            break;

        case Z:
            do_move(FRONT, dir);
            break;
        }
    }
    // FIXME

} // namespace rubik
