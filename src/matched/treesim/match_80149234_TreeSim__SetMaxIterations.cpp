// 0x80149234 (8 bytes)
// TreeSim::SetMaxIterations(int)
// SDA global: TreeSim::sMaxIterations at 0x8078D8E0 = r13[-31652]

static int TreeSim__sMaxIterations;

class TreeSim {
public:
    void SetMaxIterations(int n);
};

void TreeSim::SetMaxIterations(int n) {
    TreeSim__sMaxIterations = n;
}
