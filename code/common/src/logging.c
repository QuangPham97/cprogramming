#include "logging.h"



static const SInt8 *level_colors[] = {
    (const SInt8 *)"\x1b[94m",
    (const SInt8 *)"\x1b[36m", 
    (const SInt8 *)"\x1b[32m", 
    (const SInt8 *)"\x1b[33m", 
    (const SInt8 *)"\x1b[31m", 
    (const SInt8 *)"\x1b[35m"
};
static const SInt8 *log_level_strings[] = {
    (const SInt8 *)"TRACE", 
    (const SInt8 *)"DEBUG", 
    (const SInt8 *)"INFO", 
    (const SInt8 *)"WARN", 
    (const SInt8 *)"ERROR", 
    (const SInt8 *)"FATAL"
};

static struct {
    lock_log lock;
    UInt8 log_level;
    void *fd;
} log_context;

const SInt8 *log_level_to_string(
    UInt8 log_level
);
const SInt8 *log_level_to_string(
    UInt8 log_level
)
{
    return log_level_strings[log_level];
}

void set_log_level(
    SInt8 log_level
)
{
    log_context.log_level = log_level;
}

static void lock(
    void
)   
{
    if(log_context.lock)
    {
        log_context.lock(true, log_context.fd); 
    }
}


static void unlock(
    void
)   
{
    if(log_context.lock)
    {
        log_context.lock(false, log_context.fd); 
    }
}


void console_log(
    UInt8 log_level, 
    const SInt8 *file, 
    UInt32 line, 
    const char *function, 
    const char *msg, 
    ...
)
{
    lock();
    set_log_level(LOG_TRACE);
    if(log_context.log_level <= log_level)
    {
        va_list ap = {0};
        FILE *consle_fd = stdout;
        struct tm current_time;
        struct timeval  tv;
        gettimeofday(&tv, 0);
        localtime_r(&tv.tv_sec, &current_time);
        fprintf(consle_fd, 
                "[%02d:%02d:%02d.%06ld] [%s%-5s%s] [%s] [%u]   ", 
                current_time.tm_hour, 
                current_time.tm_min,
                current_time.tm_sec,
                tv.tv_usec, level_colors[log_level],
                log_level_to_string(log_level), "\x1b[0m",
                function, line);
        va_start(ap, msg);
        vfprintf(consle_fd, msg, ap);
        va_end(ap);
        fprintf(consle_fd, "\n");
    }
    unlock();
}