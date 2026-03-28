typedef unsigned char u8;

struct CUnlockDisplayObject {
    u8 _pad0[0x00];
    CUnlockDisplayObject* m_pNext;
    void SetMultiColorIndex(int idx);
};

struct CUnlockDisplay {
    u8 _pad0[0x464];
    CUnlockDisplayObject* m_pList;
    void SetMultiColorNumber(int num);
};

void CUnlockDisplay::SetMultiColorNumber(int num) {
    CUnlockDisplayObject* p = m_pList;
    while (p != 0) {
        p->SetMultiColorIndex(num);
        p = p->m_pNext;
    }
}
