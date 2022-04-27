#pragma once

#include <array>

#include "vector3D.hh"

namespace rubik
{
    template <typename T>
    class Matrix3D
    {
    private:
        std::array<std::array<T, 3>, 3> matrix_;

    public:
        Matrix3D(std::array<std::array<T, 3>, 3> matrix)
            : matrix_(matrix)
        {}

        T at(int i, int j)
        {
            return matrix_[i][j];
        }

        Vector3D<T> operator*(const Vector3D<T>& v) const
        {
            return Vector3D<T>{ { matrix_[0][0] * v.x + matrix_[1][0] * v.y
                                  + matrix_[2][0] * v.z },
                                { matrix_[0][1] * v.x + matrix_[1][1] * v.y
                                  + matrix_[2][1] * v.z },
                                { matrix_[0][2] * v.x + matrix_[1][2] * v.y
                                  + matrix_[2][2] * v.z } };
        }

        void transpose()
        {
            auto copy = matrix_;
            for (auto i = 0; i < 3; i++)
            {
                for (auto j = 0; j < 3; j++)
                {
                    matrix_[i][j] = copy[j][i];
                }
            }
        }
    };
    // FIXME

} // namespace rubik
