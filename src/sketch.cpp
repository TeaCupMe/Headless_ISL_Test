// #include "Logger.h"
#include "Adapter/System.h"
// #include <iostream>
#include "main.h"

void setup() {

}

void loop() {
    
    // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    IntroSatLib::system::Delay(2000);
    std::cout << "Hello, World!" << std::endl;
}