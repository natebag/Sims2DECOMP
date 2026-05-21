// 0x801116E8 ObjSelector::ResetAnimTables(void) (92B)

class AnimTable {
public:
    static void DestroyInstance(AnimTable* t);
};

class ObjSelector {
public:
    char _pad0[64];
    AnimTable* m_animTables[4];

    void ResetAnimTables();
};

void ObjSelector::ResetAnimTables() {
    short i = 0;
    AnimTable** base = m_animTables;
    AnimTable* zero = 0;
    do {
        int off = (int)i * 4;
        AnimTable* t = *(AnimTable**)((char*)base + off);
        if (t != 0) {
            AnimTable::DestroyInstance(t);
            *(AnimTable**)((char*)base + off) = zero;
        }
        i = (short)(i + 1);
    } while (i <= 3);
}
