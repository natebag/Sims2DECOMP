// 0x8014927C (8 bytes)
// TreeSim::BreakOnCallTreeStringFailure(void)
// Disassembly: lwz r3, -31632(r13); blr
// SDA global: TreeSim::sBreakOnCallTreeStringFailure at 0x8078D8F4 = r13[-31632]

static int TreeSim__sBreakOnCallTreeStringFailure;

class TreeSim {
public:
    int BreakOnCallTreeStringFailure();
};

int TreeSim::BreakOnCallTreeStringFailure() {
    return TreeSim__sBreakOnCallTreeStringFailure;
}
