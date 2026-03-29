// 0x80149244 (8 bytes)
// TreeSim::GetTooLongInPrimTime(void)
// SDA global: TreeSim::sTooLongInPrimTime at 0x8078D8E8 = r13[-31644]
// Returns float in f1

static float TreeSim__sTooLongInPrimTime;

class TreeSim {
public:
    float GetTooLongInPrimTime();
};

float TreeSim::GetTooLongInPrimTime() {
    return TreeSim__sTooLongInPrimTime;
}
