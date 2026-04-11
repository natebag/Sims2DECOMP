class cSimulatorImpl {
public:
    char pad[0x1C];
    short m_timeOfDay;

    int HourTimeOfDayLastChanged();
};

int cSimulatorImpl::HourTimeOfDayLastChanged() {
    switch (m_timeOfDay) {
        case 0: return 19;
        case 1: return 6;
        case 2: return 18;
        case 3: return 7;
        default: return -1;
    }
}
