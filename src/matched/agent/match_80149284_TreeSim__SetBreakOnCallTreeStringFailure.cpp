// 0x80149284 (8 bytes)
// TreeSim::SetBreakOnCallTreeStringFailure(bool)
// Disassembly: stw r3, -31632(r13); blr
// SDA global: TreeSim::sBreakOnCallTreeStringFailure at 0x8078D8F4 = r13[-31632]

static int TreeSim__sBreakOnCallTreeStringFailure;

class TreeSim {
public:
    void SetBreakOnCallTreeStringFailure(int val);
};

void TreeSim::SetBreakOnCallTreeStringFailure(int val) {
    TreeSim__sBreakOnCallTreeStringFailure = val;
}
