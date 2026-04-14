// 0x8014923C (8 bytes)
// TreeSim::IsBreakForPrimTimeOn(void)
// SDA global: TreeSim::sTestingTooLongInPrim at 0x8078D8E4 = r13[-31648]

static int TreeSim__sTestingTooLongInPrim;

class TreeSim {
public:
    int IsBreakForPrimTimeOn();
};

int TreeSim::IsBreakForPrimTimeOn() {
    return TreeSim__sTestingTooLongInPrim;
}
