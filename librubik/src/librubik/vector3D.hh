#pragma once

#include <fstream>
#include <iostream>
#include <vector>

namespace rubik

{
    template <typename T>
    class Vector3D
    {
    public:
        T x;
        T y;
        T z;

        bool operator==(const Vector3D& v)
        {
            return ((x == v.x) && (y == v.y) && (z == v.z));
        }
        bool operator!=(const Vector3D& v)
        {
            return ((x != v.x) || (y != v.y) || (z != v.z));
        }
    };
    template <typename T>
    inline std::ostream& operator<<(std::ostream& os, const Vector3D<T>& v)
    {
        return os << "(" << v.x << "," << v.y << "," << v.z << ")";
    }
    // FIXME

} // namespace rubik
