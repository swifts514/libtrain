#ifndef LIBTRAIN_EXCEPTION_H_
#define LIBTRAIN_EXCEOTION_H_

#include <exception>

namespace trainsys {

class BaseException : public std::exception {
   public:
    const char *what() noexcept { return "libtrain error"; }
};

}  // namespace trainsys

#endif  // LINTRAIN_EXCEPTION_H_
