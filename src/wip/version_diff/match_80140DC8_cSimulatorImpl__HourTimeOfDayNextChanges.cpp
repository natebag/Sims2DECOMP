class cSimulatorImpl {
public:
    char pad[0x1C];
    short m_timeOfDay;

    int HourTimeOfDayNextChanges();
};

int cSimulatorImpl::HourTimeOfDayNextChanges() {
    switch (m_timeOfDay) {
        case 0: return 6;
        case 1: return 7;
        case 2: return 19;
        case 3: return 18;
        default: return -1;
    }
}
