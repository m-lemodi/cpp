#include "cube.hh"

namespace rubik
{
    Cube::Cube()
    {
        for (int x = -1; x != 2; x++)
        {
            for (int y = -1; y != 2; y++)
            {
                for (int z = -1; z != 2; z++)
                {
                    Color xFace;
                    Color yFace;
                    Color zFace;

                    switch (x)
                    {
                    case -1:
                        xFace = Color::BLUE;
                        break;
                    case 0:
                        xFace = Color::NONE;
                        break;

                    case 1:
                        xFace = Color::GREEN;
                        break;
                    }

                    switch (y)
                    {
                    case -1:
                        yFace = Color::ORANGE;
                        break;
                    case 0:
                        yFace = Color::NONE;
                        break;
                    case 1:
                        yFace = Color::RED;
                        break;
                    }
                    switch (z)
                    {
                    case -1:
                        zFace = Color::YELLOW;
                        break;
                    case 0:
                        zFace = Color::NONE;
                        break;

                    case 1:
                        zFace = Color::WHITE;
                        break;
                    }
                    /*
                                        auto el = Piece
                                        {
                                            {
                                                x,
                                                y,
                                                z,
                                            },
                                            {
                                                xFace, yFace, zFace
                                            }
                                        };
                    */
                    pieces_.push_back(
                        Piece{ { x, y, z }, { xFace, yFace, zFace } });
                }
            }
        }
    }

    Cube::Cube(std::vector<Piece>& p)
        : pieces_(p)
    {}

    std::ostream& operator<<(std::ostream& os, const Cube& c)
    {
        for (auto i : c)
        {
            os << i << std::endl;
        }
        return os;
    }

    Cube Cube::from_stream(std::istream& is)
    {
        // is.open();

        if (is.eof())
        {
            throw std::invalid_argument("eof");
        }

        std::vector<Piece> read; // Vector of pieces to construct the cube
        std::string line; // read the line

        bool pcds = false;

        while (std::getline(is, line))
        {
            // std::cout << "first of all : " << line << std::endl ;

            auto tLine = std::stringstream(line);
            std::string l2;

            // std::cout << "first get line on \\n\n" ;

            std::vector<int> vcds;
            std::vector<Color> vcls;

            while (std::getline(tLine, l2, ' '))
            { // recup line par line
                // std::cout << "second get line on ' ' : " << l2 << std::endl;

                std::string tmp;

                l2 = l2.erase(l2.find(')'), 1);
                l2 = l2.erase(l2.find('('), 1);
                auto nLine = std::stringstream(l2);

                int cnt = 0;

                // std::cout << l2 << std::endl;

                while (std::getline(nLine, tmp, ','))
                {
                    // bool parsedc = false;
                    // bool parsedr = false;

                    // std::cout << tmp << std::endl;
                    if (!pcds)
                    {
                        vcds.push_back(std::stoi(tmp));
                        cnt++;
                        // std::cout << "coord cnt : " << cnt << std::endl;
                        if (cnt == 3)
                        {
                            pcds = !pcds;
                            // parsedc = true;
                        }
                        // std::cout << "coord bool : " << pcds << std::endl;
                    }

                    else
                    {
                        cnt++;
                        // std::cout << "colors cnt : "<< cnt << std::endl;

                        if (cnt == 3)
                        {
                            pcds = !pcds;
                            // parsedr = true;
                        }
                        switch (tmp.at(0))
                        {
                        case 'B':
                            vcls.push_back(Color::BLUE);
                            break;
                        case 'Y':
                            vcls.push_back(Color::YELLOW);
                            break;
                        case 'R':
                            vcls.push_back(Color::RED);
                            break;
                        case 'G':
                            vcls.push_back(Color::GREEN);
                            break;
                        case 'X':
                            vcls.push_back(Color::NONE);
                            break;
                        case 'O':
                            vcls.push_back(Color::ORANGE);
                            break;
                        case 'W':
                            vcls.push_back(Color::WHITE);
                            break;
                        }
                    }
                }
            }

            Piece p = { { vcds[0], vcds[1], vcds[2] },
                        { vcls[0], vcls[1], vcls[2] } };
            read.push_back(p);
        }

        return Cube(read);
    }

    Piece Cube::find_piece(Vector3D<Color> colors)
    {
        for (auto i : pieces_)
        {
            std::vector<Color> one = { i.colors.x, i.colors.y, i.colors.z };
            std::vector<Color> two = { colors.x, colors.y, colors.z };
            if (std::is_permutation(one.begin(), one.end(), two.begin()))
                return i;
        }
        throw std::invalid_argument("Inexistent piece");
    }

    Piece Cube::find_piece(Vector3D<int> coords)
    {
        for (auto i : pieces_)
        {
            if (i.coords == coords)
                return i;
        }
        throw std::invalid_argument("Inexistent piece");
    }

    void Cube::do_move(Move move)
    {
        if (move.mvt.index() == 0)
        { // On est une face
            // if face, need to find the pieces that belongs
            // that face and move
            Face f = std::get<Face>(move.mvt);

            for (auto i : pieces_)
            {
                switch (f)
                {
                case Face::UP:
                    if (i.coords.z == 1)
                        i.do_move(f, move.dir);
                    break;

                case Face::DOWN:
                    if (i.coords.z == -1)
                        i.do_move(f, move.dir);
                    break;

                case Face::LEFT:
                    if (i.coords.y == -1)
                        i.do_move(f, move.dir);
                    break;

                case Face::RIGHT:
                    if (i.coords.y == 1)
                        i.do_move(f, move.dir);
                    break;

                case Face::FRONT:
                    if (i.coords.x == 1)
                        i.do_move(f, move.dir);
                    break;

                case Face::BACK:
                    if (i.coords.x == -1)
                        i.do_move(f, move.dir);
                    break;
                }
            }
        }
        else
        { // On est un axis
            // if axis move all the cube coordinates on all the pieces
            Axis a = std::get<Axis>(move.mvt);
            for (auto i : pieces_)
            {
                i.do_move(a, move.dir);
            }
        }
        if (move.is_double)
        {
            move.is_double = false;
            do_move(move);
        }
    }

    void Cube::do_moves(std::vector<Move> moves)
    {
        for (auto i : moves)
        {
            do_move(i);
        }
    }

    void Cube::undo_move(Move move)
    {
        Move reverse = move;

        if (move.dir == Direction::CLOCKWISE)
            reverse.dir = Direction::ANTI_CLOCKWISE;
        else
            reverse.dir = Direction::CLOCKWISE;

        do_move(reverse);
    }

    void Cube::undo_moves(std::vector<Move> moves)
    {
        for (auto i = moves.end(); i != moves.begin(); i--)
        {
            undo_move(*i);
        }
    }

} // namespace rubik