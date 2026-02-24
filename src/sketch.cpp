#include <main.h>
#include <main.h>

#include "AccelerometerV2.h"
#include "GyroscopeV2.h"
#include "MagnetometerV2.h"

using namespace IntroSatLib;

uint32_t lastMessageTime = 0;

AccelerometerV2 acc(Wire);
GyroscopeV2 gyro(Wire);
MagnetometerV2 magn(Wire);

void setup() {
    Wire.begin();
    Serial.begin(115200, SERIAL_8E1);
    Serial.println("Begin!");

    acc.Init(AccelerometerV2::Scale::fourG);
    gyro.Init(GyroscopeV2::Scale::DPS0500);
    magn.Init(MagnetometerV2::Scale::G8);
    
}

void loop() {
    if (millis() - lastMessageTime > 2000) {
        Serial.print("ax: ");
        Serial.println(acc.X());
        Serial.print("gy: ");
        Serial.println(acc.Y());
        lastMessageTime = millis();
    }
}