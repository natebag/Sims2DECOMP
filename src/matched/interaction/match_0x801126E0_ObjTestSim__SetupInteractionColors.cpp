/* ObjTestSim::SetupInteractionColors(Interaction*, short) - 0x801126E0 (60 bytes) */

struct Interaction {
    char pad[0x3C];
    int m_flags;
};

class ObjTestSim {
public:
    static void SetupInteractionColors(Interaction* inter, short color);
};

void ObjTestSim::SetupInteractionColors(Interaction* inter, short color) {
    int f = inter->m_flags;
    f &= ~0x10;
    inter->m_flags = f;
    if (color == 1) {
        inter->m_flags = f | 0x10;
    }
    f = inter->m_flags;
    f &= ~0x800;
    inter->m_flags = f;
    if (color == 2) {
        inter->m_flags = f | 0x800;
    }
}
