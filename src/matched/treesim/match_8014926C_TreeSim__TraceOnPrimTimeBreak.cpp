// 0x8014926C (8 bytes)
// TreeSim::TraceOnPrimTimeBreak(void)
// Disassembly: lwz r3, -31636(r13); blr
// SDA global: TreeSim::sTraceOnlyOnPrimBreak at 0x8078D8F0 = r13[-31636]

static int TreeSim__sTraceOnlyOnPrimBreak;

class TreeSim {
public:
    int TraceOnPrimTimeBreak();
};

int TreeSim::TraceOnPrimTimeBreak() {
    return TreeSim__sTraceOnlyOnPrimBreak;
}
