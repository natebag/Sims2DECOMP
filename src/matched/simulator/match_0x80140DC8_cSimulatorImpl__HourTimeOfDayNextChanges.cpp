// 0x80140DC8 cSimulatorImpl::HourTimeOfDayNextChanges(void) (88B)
struct cSimulatorImpl {
    char pad[28];
    short m_timeOfDay;
};

int cSimulatorImpl__HourTimeOfDayNextChanges(cSimulatorImpl* self) {
    switch (self->m_timeOfDay) {
        case 2: return 6;
        case 3: return 7;
        case 1: return 19;
        case 0: return 18;
    }
    return -1;
}
