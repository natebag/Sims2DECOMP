// 0x80140D28 cSimulatorImpl::ComputeTimeOfDay (72B)

struct cSimulatorImpl {
    char pad[20];
    short m_hour;
    int ComputeTimeOfDay();
};

int cSimulatorImpl::ComputeTimeOfDay() {
    short hour = m_hour;
    if (hour <= 5) return 2;
    if (hour <= 6) return 3;
    if (hour > 17) {
        int rv = 2;
        if (hour > 18) return rv;
        return 1;
    }
    return 0;
}
