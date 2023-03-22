#ifndef LIBTRAIN_STATIC_STRING_H_
#define LIBTRAIN_STATIC_STRING_H_

#include <cstring>
#include <iostream>
#include <string>

namespace trainsys {

template <size_t maxlen>
class StaticString {
   private:
    size_t len;
    char str[maxlen + 2];

   public:
    StaticString();
    explicit StaticString(const char *str_);
    explicit StaticString(const std::string &str_);
    explicit StaticString(const StaticString<maxlen> &str_);
    ~StaticString();

    StaticString &operator=(const char *str_);
    StaticString &operator=(const std::string &str_);
    StaticString &operator=(const StaticString<maxlen> &str_);

    // actual length and maximum length of static string
    int length() const;
    int maxLength() const;

    // expose &str[0]
    const char *c_str() const;
    // conversion to std::string
    operator std::string() const;

    // accessor
    char &operator[](size_t idx);
    const char &operator[](size_t idx) const;
};

template <size_t maxlen>
std::istream &operator>>(std::istream &is, StaticString<maxlen> &obj);

template <size_t maxlen>
std::ostream &operator<<(std::ostream &os, const StaticString<maxlen> &obj);

template <size_t maxlen1, size_t maxlen2>
bool operator==(const StaticString<maxlen1> &lhs, const StaticString<maxlen2> &rhs);

template <size_t maxlen1, size_t maxlen2>
bool operator<(const StaticString<maxlen1> &lhs, const StaticString<maxlen2> &rhs);

}  // namespace trainsys

#include "static_string_impl.h"

namespace trainsys {

const size_t MAX_TRAINID_LEN = 10;
const size_t MAX_STATIONID_LEN = 20;

using TrainID = StaticString<MAX_TRAINID_LEN>;
using StationID = StaticString<MAX_STATIONID_LEN>;

}  // namespace trainsys

#endif  // LIBTRAIN_STATIC_STRING_H_
