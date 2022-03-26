#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>
#include "types.h"

#define LOG_VERSION "0.1.0"

typedef struct _logging_t
{
    /* data */
    va_list         va;
    const SInt8     msg;
    const SInt8     *file;
    const SInt8     *function;
    struct tm       *time;
    UInt32          line;
    UInt8           log_level;
}logging_t;
typedef void (*lock_log)(bool lock, void *fd);

enum {
    LOG_TRACE, 
    LOG_DEBUG, 
    LOG_INFO, 
    LOG_WARN, 
    LOG_ERROR, 
    LOG_FATAL 
};

// #define log_trace(LOG_TRACE, msg, ...) console_log(LOG_TRACE, __FILE__, __LINE__, __FUNCTION__, msg, ##__VA_ARGS__)
// #define log_debug(LOG_DEBUG, msg, ...) console_log(LOG_DEBUG, __FILE__, __LINE__, __FUNCTION__, msg, ##__VA_ARGS__)
// #define log_info(LOG_INFO, msg, ...)   console_log(LOG_INFO,  __FILE__, __LINE__, __FUNCTION__, msg, ##__VA_ARGS__)
// #define log_warn(LOG_WARN, msg, ...)   console_log(LOG_WARN,  __FILE__, __LINE__, __FUNCTION__, msg, ##__VA_ARGS__)
// #define log_error(LOG_ERROR, msg, ...) console_log(LOG_ERROR, __FILE__, __LINE__, __FUNCTION__, msg, ##__VA_ARGS__)
// #define log_fatal(LOG_FATAL, msg, ...) console_log(LOG_FATAL, __FILE__, __LINE__, __FUNCTION__, msg, ##__VA_ARGS__)

#define LOG_MSG(log_level, msg, ...) \
    {\
        if(log_level == LOG_TRACE) \
        {\
            console_log(LOG_TRACE, __FILE__, __LINE__, __FUNCTION__, (const char *)msg, ##__VA_ARGS__);\
        }else if(log_level == LOG_DEBUG)\
        {\
            console_log(LOG_DEBUG, __FILE__, __LINE__, __FUNCTION__, (const char *)msg, ##__VA_ARGS__);\
        }else if(log_level == LOG_INFO)\
        {\
            console_log(LOG_INFO, __FILE__, __LINE__, __FUNCTION__, (const char *)msg, ##__VA_ARGS__);\
        }else if(log_level == LOG_WARN)\
        {\
            console_log(LOG_WARN, __FILE__, __LINE__, __FUNCTION__, (const char *)msg, ##__VA_ARGS__);\
        }else if(log_level == LOG_FATAL)\
        {\
            console_log(LOG_FATAL, __FILE__, __LINE__, __FUNCTION__, (const char *)msg, ##__VA_ARGS__);\
        }\
    }


void set_log_level(
    SInt8 log_level
);

void console_log(
    UInt8 log_level, 
    const SInt8 *file, 
    UInt32 line, 
    const char *function, 
    const char *msg, 
    ...
);
#endif