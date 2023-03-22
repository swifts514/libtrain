#ifndef LIBTRAIN_UTILITY_H_
#define LIBTRAIN_UTILITY_H_

#include <iostream>

namespace trainsys {

// suggest using std::pair and std::tuple instead

template <typename T1, typename T2>
struct Pair {
    T1 first;
    T2 second;

    Pair();
    Pair(const T1 &first_, const T2 &second_);
    Pair(const Pair<T1, T2> &obj);
    ~Pair();
    Pair &operator=(const Pair<T1, T2> &obj);
};

template <typename T1, typename T2>
std::istream &operator>>(std::istream &is, Pair<T1, T2> &obj);
template <typename T1, typename T2>
std::ostream &operator<<(std::istream &os, const Pair<T1, T2> &obj);

template <typename T1, typename T2>
bool operator==(const Pair<T1, T2> &lhs, const Pair<T1, T2> &rhs);
template <typename T1, typename T2>
bool operator<(const Pair<T1, T2> &lhs, const Pair<T1, T2> &rhs);

template <typename T1, typename T2, typename T3>
struct Triple {
    T1 first;
    T2 second;
    T3 third;

    Triple();
    Triple(const T1 &first_, const T2 &second_, const T3 &third_);
    Triple(const Triple<T1, T2, T3> &obj);
    ~Triple();
    Triple &operator=(const Triple<T1, T2> &obj);
};

template <typename T1, typename T2, typename T3>
std::istream &operator>>(std::istream &is, Triple<T1, T2, T3> &obj);
template <typename T1, typename T2, typename T3>
std::ostream &operator<<(std::istream &os, const Triple<T1, T2, T3> &obj);

template <typename T1, typename T2, typename T3>
bool operator==(const Triple<T1, T2, T3> &lhs, const Triple<T1, T2, T3> &rhs);
template <typename T1, typename T2, typename T3>
bool operator<(const Triple<T1, T2, T3> &lhs, const Triple<T1, T2, T3> &rhs);

}  // namespace trainsys

#include "utility_impl.h"

#endif  // LIBTRAIN_UTILITY_H_
