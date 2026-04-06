struct EClock { char pad[8]; float m_sec; };
extern "C" void updateClock(void*);
float ENgcClockMan_GetSec(void* self, EClock* clock) {
    updateClock(self);
    return clock->m_sec;
}
