#include "v_debug.h"
#include <stdio.h>
#include <stdarg.h>
#include "v_core/v_core.h"

void debugf(const char *format, ...)
{
    va_list args;
    printf(FTIME("[T+%8d]") FTAG("[DEBUG]"), millis());
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

void debugf_raw(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

// void debugf_tagged(const char* tag, const char *format, ...)
// {
//     va_list args;
//     printf("[DEBUG][%s]: ", tag);
//     va_start(args, format);
//     vprintf(format, args);
//     va_end(args);
// }