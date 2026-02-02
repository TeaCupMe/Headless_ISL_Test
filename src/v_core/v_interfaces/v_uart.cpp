#include "v_uart.h"
#include <stdio.h>
#include <string.h>
#include "v_core/v_interfaces/v_interface.h"

V_UART::V_UART(uint8_t _id, void (*_outputBytes)(uint8_t*, uint16_t)): id(_id), outputBytes(_outputBytes)
{
}

template <typename... Args>
void V_UART::_debugf(const char *format, Args&&... args)
{
    debugf(FINTERFACE("[UART-%d]")" ", this->id);
    debugf_raw(format, args...);
}

template <typename... Args>
void V_UART::_debugf_raw(const char *format, Args&&... args)
{
    debugf_raw(format, args...);
}

void V_UART::begin(uint32_t _baudrate, uint8_t _config)
{
    baudrate = _baudrate;
    config = _config;

    uint8_t word = 5 + ((config & 0b0110) >> 1);
    uint8_t parityBits = 1 + ((config & 0b1000) >> 3);
    char parity = ((config >> 4) == 0) ? 'N' : ((config >> 4) == 2) ? 'E' : 'O';

    _debugf("Starting at " FDATA("%d") " baud, " FDATA("%d") "-bit word, with " FDATA("%d") " parity " FDATA("%c") " bit(s)\n", baudrate, word, parityBits, parity);

}

void V_UART::print(uint64_t data)
{
    _debugf("Printing " FDATA("%ld") "\n", data);
}

void V_UART::print(uint32_t data)
{
    print((uint64_t)data);
}

void V_UART::print(uint16_t data)
{
    print((uint64_t)data);
}

void V_UART::print(uint8_t data)
{
    print((uint64_t)data);
}

void V_UART::print(float data)
{
    _debugf("Printing " FDATA("%f") "\n", data);
}

void V_UART::print(const char *str)
{
    _debugf("Printing: \"" FDATA("%s")"\". HEX: [", str);
    for (uint16_t i = 0; i < strlen(str) - 1; i++) {
        _debugf_raw( FDATA("%02X") " ", (uint8_t)(str[i]));
    }
    
    _debugf_raw(FDATA("%02X") "]\n", (uint8_t)(str[strlen(str) - 1]));
}

void V_UART::println(uint64_t data)
{
    _debugf("Printing " FDATA("%ld") "with newline\n", data);
}

void V_UART::println(uint32_t data)
{
    println((uint64_t)data);
}

void V_UART::println(uint16_t data)
{
    println((uint64_t)data);
}

void V_UART::println(uint8_t data)
{
    println((uint64_t)data);
}

void V_UART::println(float data)
{
    _debugf("Printing " FDATA("%f") " with newline\n", data);
}

void V_UART::println(const char *str)
{
    _debugf("Printing: \"" FDATA("%s") "\" with newline. HEX: [", str);
    for (uint16_t i = 0; i < strlen(str) - 1; i++) {
        _debugf_raw( FDATA("%02X") " ", (uint8_t)(str[i]));
    }
    
    _debugf_raw(FDATA("%02X") " " FDATA("%02X") "]\n", (uint8_t)(str[strlen(str) - 1]), (uint8_t)'\n');
}

void V_UART::write(uint8_t *buf, uint16_t len)
{
     _debugf("Writing: \nCHAR: ");
    for (uint16_t i = 0; i < len; i++) {
        _debugf_raw( FDATA(" %c") " ", (char)(buf[i]));
    }
    _debugf_raw("\n HEX: ");
    for (uint16_t i = 0; i < len; i++) {
        _debugf_raw( FDATA("%02X") " ", (char)(buf[i]));
    }
    
    _debugf_raw("\n");
}

uint16_t V_UART::available()
{
    return strlen((const char*)this->rx_buffer);
}

void loseData(uint8_t* data, uint16_t len) {
    (void) data;
    (void) len;
}

V_UART Serial(0, loseData);
V_UART Serial1(1, loseData);
V_UART Serial2(2, loseData);