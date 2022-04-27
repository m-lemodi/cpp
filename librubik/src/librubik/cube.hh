#pragma once

#include <algorithm>
#include <array>
#include <sstream>
#include <string>
#include <variant>

#include "color.hh"
#include "matrix3D.hh"
#include "move.hh"
#include "piece.hh"
#include "vector3D.hh"

namespace rubik
{
    class Cube
    {
    private:
        std::vector<Piece> pieces_;

    public:
        Cube();
        Cube(std::vector<Piece>& p);
        static Cube from_stream(std::istream& is);

        std::vector<Piece>::iterator begin()
        {
            return pieces_.begin();
        }
        std::vector<Piece>::iterator end()
        {
            return pieces_.end();
        }
        std::vector<Piece>::const_iterator begin() const
        {
            return pieces_.begin();
        }
        std::vector<Piece>::const_iterator end() const
        {
            return pieces_.end();
        }

        Piece find_piece(Vector3D<int> coords);
        Piece find_piece(Vector3D<Color> colors);

        friend std::ostream& operator<<(std::ostream& os, const Cube& c);

        void do_move(Move move);
        void do_moves(std::vector<Move> moves);
        void undo_move(Move move);
        void undo_moves(std::vector<Move> moves);
    };
    // FIXME

} // namespace rubik
