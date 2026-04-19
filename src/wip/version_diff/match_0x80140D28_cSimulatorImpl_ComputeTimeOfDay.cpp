// FLAGS: -fno-reorder-blocks
// 0x80140D28 (72B)
// cSimulatorImpl::ComputeTimeOfDay(void)

struct cSimulatorImpl_TD {
    char pad[20];
    short m_hour;
    int ComputeTimeOfDay();
};

int cSimulatorImpl_TD::ComputeTimeOfDay() {
    short hour = m_hour;
    if (hour <= 5) return 2;
    if (hour <= 6) return 3;
    if (hour <= 17) return 0;
    if (hour > 18) return 2;
    return 1;
}
