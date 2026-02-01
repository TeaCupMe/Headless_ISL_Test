#include <iostream>

#include "main.h"
#include <thread>
#include <chrono>

int main() {


    setup();
    while (true) {
        loop();
    }
    return 0;
}