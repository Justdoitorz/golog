#include "golog.h"
#include <stdio.h>
#include <stdarg.h>

__attribute__((weak))
const char *golog_tostring_lv(unsigned lv)
{
    static const char *lv_str[] = {
        "U", //"UNKNOWN",

        "F", //"FATAL",
        "E", //"ERROR",
        "W", //"WARN",
        "I", //"INFO",
        "D", //"DEBUG",
        "V", //"VERBOSE",
    };

    return lv <= GOLOG_LEVEL_VERBOSE ? lv_str[lv] : lv_str[0];
}

__attribute__((weak))
int golog_function(unsigned lv, const char *tag, const char *fmt, ...)
{
    int ret = fprintf(stderr, "%s %s: ", golog_tostring_lv(lv), tag);

    va_list ap; 
    va_start(ap, fmt);
    ret += vfprintf(stderr, fmt, ap);
    va_end(ap);

    return ret;
}

