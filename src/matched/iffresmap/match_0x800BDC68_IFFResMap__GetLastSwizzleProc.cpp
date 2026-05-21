// 0x800BDC68 (72B) IFFResMap::GetLastSwizzleProc(unsigned int)

class Res {
public:
    char pad[20];
    void* m_14;
};

class IFFResMap {
public:
    void* m_0;
    Res* m_4;
    Res* GetResList(unsigned int id, bool flag);
    void* GetLastSwizzleProc(unsigned int id);
};

void* IFFResMap::GetLastSwizzleProc(unsigned int id) {
    Res* r = GetResList(id, false);
    if (r == m_4) return 0;
    return r->m_14;
}
