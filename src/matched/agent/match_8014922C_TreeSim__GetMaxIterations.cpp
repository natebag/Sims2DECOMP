// 0x8014922C (8 bytes)
// TreeSim::GetMaxIterations(void)
// SDA global: TreeSim::sMaxIterations at 0x8078D8E0 = r13[-31652]

static int TreeSim__sMaxIterations;

class TreeSim {
public:
    static int& _sMaxIterations() { return TreeSim__sMaxIterations; }
    int GetMaxIterations();
};

int TreeSim::GetMaxIterations() {
    return TreeSim__sMaxIterations;
}
