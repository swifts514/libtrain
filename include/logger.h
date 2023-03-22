#ifndef LIBTRAIN_LOGGER_H_
#define LIBTRAIN_LOGGER_H_

#include <string>

namespace trainsys {

enum LogLevel { TRACE, INFO, WARN, FATAL, NEVER };

class Logger {
   private:
    LogLevel log_level;

   public:
    Logger();
    Logger(LogLevel level);

    LogLevel getLogLevel();
    void setLogLevel(LogLevel level);

    void log(const std::string &msg, LogLevel level);
    void trace(const std::string &msg);
    void info(const std::string &msg);
    void warn(const std::string &msg);
    void fatal(const std::string &msg);
};

}  // namespace trainsys

#endif  // LINTRAIN_LOGGER_H_
