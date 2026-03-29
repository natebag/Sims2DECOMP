// 0x80149250 (8 bytes)
// TreeSim::SetBreakForPrimTime(float) — stores float to sTooLongInPrimTime
// Disassembly: stfs f1, -31644(r13)
// SDA global: TreeSim::sTooLongInPrimTime at 0x8078D8E8 = r13[-31644]

static float TreeSim__sTooLongInPrimTime;

class TreeSim {
public:
    void SetBreakForPrimTime(float t);
};

void TreeSim::SetBreakForPrimTime(float t) {
    TreeSim__sTooLongInPrimTime = t;
}
