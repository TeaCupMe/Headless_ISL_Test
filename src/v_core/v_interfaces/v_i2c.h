#ifndef V_I2C_H_
#define V_I2C_H_
#include "stdint.h"
#include "v_core/v_debug.h"
// #include <stdarg.h>

class V_I2C {


    uint8_t id;
    uint8_t addr = 0;
    template <typename... Args>
    void _debugf(const char *format, Args&&... args);

    template <typename... Args>
    void _debugf_raw(const char *format, Args&&... args);
public:
    V_I2C(uint8_t _id): id(_id) {}

    void begin(uint8_t _addr = 0);

    bool IsReady(uint8_t address);

    uint16_t Receive(uint8_t address, uint8_t* buf, uint16_t count);
    bool Transmit(uint8_t address, uint8_t* buf, uint16_t count);

    // bool ReadMem(uint8_t address, uint16_t reg, uint8_t* buf, uint16_t count);
    // bool WriteMem(uint8_t address, uint16_t reg, uint8_t* buf, uint16_t count);

};

// void 

extern V_I2C Wire;
extern V_I2C Wire1;
extern V_I2C Wire2;

#endif /* V_I2C_H_ */

