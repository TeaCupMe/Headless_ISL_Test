#include "v_core.h"
#include "Adapter/System.h"
#include "stdint.h"

void setExecutionStart() {
    __execution_start_time__ = std::chrono::steady_clock::now();
}

uint32_t millis()
{
    return IntroSatLib::system::GetTick();
}
