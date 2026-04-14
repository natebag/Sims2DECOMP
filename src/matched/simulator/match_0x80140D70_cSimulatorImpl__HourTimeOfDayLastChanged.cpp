// 0x80140D70 cSimulatorImpl::HourTimeOfDayLastChanged(void) (88B)
struct cSimulatorImpl {
    char pad[28];
    short m_timeOfDay;
};

int cSimulatorImpl__HourTimeOfDayLastChanged(cSimulatorImpl* self) {
    switch (self->m_timeOfDay) {
        case 2: return 19;
        case 3: return 6;
        case 1: return 18;
        case 0: return 7;
    }
    return -1;
}
