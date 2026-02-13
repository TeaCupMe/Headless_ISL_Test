#ifndef V_CORE_H_
#define V_CORE_H_

#include <thread>
#include <chrono>

#include "v_interface/v_i2c.h"
#include "v_interface/v_uart.h"

extern std::chrono::time_point<std::chrono::steady_clock> __execution_start_time__;

void setExecutionStart();
uint32_t millis();


#endif /* V_CORE_H_ */