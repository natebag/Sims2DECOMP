// 0x8014924C (12 bytes)
// TreeSim::SetTooLongInPrimTime(bool, float)
// Disassembly: stw r3, -31648(r13); stfs f1, -31644(r13); blr
// SDA globals: sTestingTooLongInPrim at r13[-31648], sTooLongInPrimTime at r13[-31644]

static int TreeSim__sTestingTooLongInPrim;
static float TreeSim__sTooLongInPrimTime;

class TreeSim {
public:
    void SetTooLongInPrimTime(int enable, float t);
};

void TreeSim::SetTooLongInPrimTime(int enable, float t) {
    TreeSim__sTestingTooLongInPrim = enable;
    TreeSim__sTooLongInPrimTime = t;
}
