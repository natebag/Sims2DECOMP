// 0x80149260 (12 bytes)
// TreeSim::SetTooLongInTickTime(bool, float)
// Disassembly: stw r3, -31648(r13); stfs f1, -31640(r13); blr
// SDA globals: sTestingTooLongInPrim at r13[-31648], sTooLongInTickTime at r13[-31640]

static int TreeSim__sTestingTooLongInPrim;
static float TreeSim__sTooLongInTickTime;

class TreeSim {
public:
    void SetTooLongInTickTime(int enable, float t);
};

void TreeSim::SetTooLongInTickTime(int enable, float t) {
    TreeSim__sTestingTooLongInPrim = enable;
    TreeSim__sTooLongInTickTime = t;
}
