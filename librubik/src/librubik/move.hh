#pragma once
#include <algorithm>
#include <array>
#include <sstream>
#include <string>
#include <variant>

namespace rubik
{
    enum Axis
    {
        X,
        Y,
        Z
    };

    enum Direction
    {
        CLOCKWISE,
        ANTI_CLOCKWISE
    };

    enum Face
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        FRONT,
        BACK
    };

    class Move
    {
    public:
        std::variant<Face, Axis> mvt;
        Direction dir = CLOCKWISE;
        bool is_double = false;
    };

    // std::vector<Move> parse_moves(std::string input);

    // FIXME

} // namespace rubik
