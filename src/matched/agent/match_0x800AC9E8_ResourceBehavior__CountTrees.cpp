// 0x800AC9E8 ResourceBehavior::CountTrees(short) (80B)

class ResourceBehavior {
public:
    char pad0[16];
    void* m_16;
    void* m_20;
    void* m_24;
    int CountTrees(short type);
};

int ResourceBehavior::CountTrees(short type) {
    void* p = 0;
    if (type == 2) goto cs2;
    if (type > 2) goto check3;
    if (type == 1) goto cs1;
    goto common;
check3:
    if (type == 3) goto cs3;
    goto common;
cs1:
    p = m_24;
    goto common;
cs2:
    p = m_16;
    goto common;
cs3:
    p = m_20;
common:
    if (p == 0) return 0;
    return *(int*)((char*)p + 24);
}
