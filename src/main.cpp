#include <iostream>

#include "main.h"
#include <thread>
#include <chrono>




int main() {
    debugf("Initializing\n");
    setExecutionStart();
    debugf("Execution start time set\n");

    setup();
    debugf("setup() completed\n");
    while (true) {
        loop();
    }
    return 0;
}