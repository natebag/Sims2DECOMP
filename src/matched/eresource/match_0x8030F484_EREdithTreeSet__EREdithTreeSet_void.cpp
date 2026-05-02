// 0x8030F484 (72B) EREdithTreeSet::EREdithTreeSet(void)
// SI ctor — EResource base + 3 stores (vtable + 2 zeros).

extern char vt_EREdithTreeSet[];

class EResource {
public:
    void* m_vt;
    EResource();
};

class EREdithTreeSet : public EResource {
public:
    char pad04_13[0x14 - 4];
    int m_field14;
    char pad18_1B[0x1C - 0x18];
    int m_field1C;
    EREdithTreeSet();
};

EREdithTreeSet::EREdithTreeSet() {
    m_field14 = 0;
    m_vt = (void*)vt_EREdithTreeSet;
    m_field1C = 0;
}
