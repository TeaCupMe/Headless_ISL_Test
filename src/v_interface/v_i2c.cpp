#include "v_interface/v_i2c.h"
#include "v_interface/v_debug.h"
#include "v_interface/v_interface.h"
#include "v_i2c.h"
#include <stdarg.h>

void V_I2C::begin(uint8_t _addr)
{
    if (addr) {
        _debugf("Starting as " FDATA("slave") " at address " FDATA("%d") "\n", addr);
        addr = _addr;
    } else {
        _debugf("Starting as " FDATA("master") " \n");
    }
}

template <typename... Args>
void V_I2C::_debugf(const char *format, Args&&... args)
{
    debugf(FINTERFACE("[I2C-%d]") " ", this->id);
    debugf_raw(format, args...);
}

template <typename... Args>
void V_I2C::_debugf_raw(const char *format, Args&&... args)
{
    debugf_raw(format, args...);
}

bool V_I2C::IsReady(uint8_t address)
{
    _debugf("Checking if device " FADDR("0x%2X")" is ready\n", address);
    return true;
}

uint16_t V_I2C::Receive(uint8_t address, uint8_t *buf, uint16_t count)
{
    _debugf("Requesting %d byte(s) from device " FADDR("0x%2X")"\n", count, address);
    return count;
}

bool V_I2C::Transmit(uint8_t address, uint8_t *buf, uint16_t count)
{
    _debugf("Transmitting %d byte(s) to device " FADDR("0x%2X")": [", count, address);
    for (uint16_t i = 0; i < count - 1; i++) {
        _debugf_raw(FDATA("0x%02X") ", ", buf[i]);
    }
    _debugf_raw(FDATA("0x%02X") "]\n", buf[count-1]);

    return true;
}

// bool V_I2C::ReadMem(uint8_t address, uint16_t reg, uint8_t *buf, uint16_t count)
// {
//     return false;
// }

// bool V_I2C::WriteMem(uint8_t address, uint16_t reg, uint8_t *buf, uint16_t count)
// {
//     return false;
// }

V_I2C Wire(0);
V_I2C Wire1(1);
V_I2C Wire2(2);