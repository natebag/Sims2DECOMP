/* cSimulatorImpl::ComputeTimeOfDay(void) at 0x80140D28 (72B) */

struct cSimulatorImpl {
    char pad[20];
    short m_hour;
    int ComputeTimeOfDay();
};

int cSimulatorImpl::ComputeTimeOfDay() {
    short hour = m_hour;
    if (hour <= 5) {
        return 2;
    } else if (hour <= 6) {
        return 3;
    } else if (hour <= 17) {
        return 0;
    } else if (hour <= 18) {
        return 1;
    }
    return 2;
}
