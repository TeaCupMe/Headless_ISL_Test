#ifndef V_UART_H_
#define V_UART_H_
#include "stdint.h"
#include "v_interface/v_debug.h"
#include "v_interface/v_uart_defines.h"

class V_UART {
    uint8_t id;
    uint32_t baudrate;
    uint8_t config;

    bool started;
    uint8_t* rx_buffer;

    void (*outputBytes)(uint8_t*, uint16_t) = nullptr;

    template <typename... Args>
    void _debugf(const char *format, Args&&... args);

    template <typename... Args>
    void _debugf_raw(const char *format, Args&&... args);
public:
    V_UART(uint8_t _id, void (*_outputBytes)(uint8_t*, uint16_t));

    void begin(uint32_t _baudrate, uint8_t _config);

    void print(uint64_t);
    void print(uint32_t);
    void print(uint16_t);
    void print(uint8_t);
    void print(float);
    void print(const char* str);

    void println(uint64_t);    
    void println(uint32_t);
    void println(uint16_t);
    void println(uint8_t);
    void println(float);
    void println(const char* str);

    void write(uint8_t* buf, uint16_t len);

    uint16_t available();
};

extern V_UART Serial;
extern V_UART Serial1;
extern V_UART Serial2;

#endif /* V_UART_H_ */