// 0x8014928C (8 bytes)
// TreeSim::IsExecutingInMainSim(void)
// Disassembly: lwz r3, -31656(r13); blr
// SDA global: TreeSim::sInMainSim at 0x8078D8DC = r13[-31656]

static int TreeSim__sInMainSim;

class TreeSim {
public:
    int IsExecutingInMainSim();
};

int TreeSim::IsExecutingInMainSim() {
    return TreeSim__sInMainSim;
}
