#include "bimap.hh"

template <typename T1, typename T2>
void Bimap<T1, T2>::insert(const T1& v1, const T2& v2)
{
    lhs.insert({ v1, v2 });
    rhs.insert({ v2, v1 });
}

template <typename T1, typename T2>
void Bimap<T1, T2>::insert(const T2& v1, const T1& v2)
{
    rhs.insert({ v1, v2 });
    lhs.insert({ v2, v1 });
}

template <typename T1, typename T2>
void Bimap<T1, T2>::erase(const T1& v)
{
    auto finder = lhs.find(v);
    auto tmp = finder->second;
    lhs.erase(v);
    rhs.erase(tmp);
}

template <typename T1, typename T2>
void Bimap<T1, T2>::erase(const T2& v)
{
    auto finder = rhs.find(v);
    auto tmp = finder->second;
    rhs.erase(v);
    lhs.erase(tmp);
}

template <typename T1, typename T2>
Bimap<T1, T2>::iteratorT1 Bimap<T1, T2>::find(const T1& v)
{
    return lhs.find(v);
}

template <typename T1, typename T2>
Bimap<T1, T2>::iteratorT2 Bimap<T1, T2>::find(const T2& v)
{
    return rhs.find(v);
}

template <typename T1, typename T2>
std::size_t Bimap<T1, T2>::size() const
{
    return lhs.size() > 0 ? lhs.size() : 0;
}

template <typename T1, typename T2>
void Bimap<T1, T2>::clear()
{
    lhs.clear();
    rhs.clear();
}
