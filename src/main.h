#include <thread>
#include <chrono>

#include <stdio.h>
#include <stdarg.h>

extern void setup();
extern void loop();

void getExecutionStart() {
    static auto __execution_start_time__ = std::chrono::steady_clock::now();
}

void debugf(const char* format, ...) {
    va_list args;

    // Optional: Add custom prefix or logic
    printf("[DEBUG]: ");

    // Initialize the argument list
    va_start(args, format);

    // Use vprintf (or vfprintf, vsnprintf) to pass the arguments
    vprintf(format, args);

    // Clean up the argument list
    va_end(args);
}