/* ObjSelector::GetHasGraphics(void) - 0x801110C0 (48B) */

struct ObjTree {
    char pad0[8];
    short m_short_8;
    char pad1[10];
    short m_short_20;
};

class ObjSelector {
public:
    char pad[56];
    ObjTree* m_tree;

    int GetHasGraphics(void);
};

int ObjSelector::GetHasGraphics(void) {
    ObjTree* tree = m_tree;
    if (tree->m_short_20 != 0) return 1;
    int r = 1;
    if (tree->m_short_8 == 0) r = 0;
    return r;
}
