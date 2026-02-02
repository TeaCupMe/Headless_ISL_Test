#ifndef V_DEBUG_H_
#define V_DEBUG_H_

#include "v_core/ansi_escape_codes.h"

#define FTIME(X) ANSI_BACKGROUND_WHITE ANSI_COLOR_BLACK X ANSI_COLOR_RESET
#define FTAG(X) ANSI_HIGH_INT_GREEN X ANSI_COLOR_RESET


void debugf(const char* format, ...);
void debugf_raw(const char *format, ...);

// void debugf_tagged(const char* tag, const char *format, ...);
#endif /* V_DEBUG_H_ */
