// 0x80149258 (8 bytes)
// TreeSim::GetTooLongInTickTime(void)
// SDA global: TreeSim::sTooLongInTickTime at 0x8078D8EC = r13[-31640]
// Returns float in f1

static float TreeSim__sTooLongInTickTime;

class TreeSim {
public:
    float GetTooLongInTickTime();
};

float TreeSim::GetTooLongInTickTime() {
    return TreeSim__sTooLongInTickTime;
}
