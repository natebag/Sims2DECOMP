// 0x80149274 (8 bytes)
// TreeSim::SetTraceOnPrimTimeBreak(bool)
// Disassembly: stw r3, -31636(r13); blr
// SDA global: TreeSim::sTraceOnlyOnPrimBreak at 0x8078D8F0 = r13[-31636]

static int TreeSim__sTraceOnlyOnPrimBreak;

class TreeSim {
public:
    void SetTraceOnPrimTimeBreak(int val);
};

void TreeSim::SetTraceOnPrimTimeBreak(int val) {
    TreeSim__sTraceOnlyOnPrimBreak = val;
}
