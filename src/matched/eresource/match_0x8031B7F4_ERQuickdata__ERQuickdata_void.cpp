// 0x8031B7F4 (72B) ERQuickdata::ERQuickdata(void)
// SI ctor — EResource base + 3 stores (vtable + 2 zeros).

extern char vt_ERQuickdata[];

class EResource {
public:
    void* m_vt;
    EResource();
};

class ERQuickdata : public EResource {
public:
    char pad04_13[0x14 - 4];
    int m_field14;
    int m_field18;
    ERQuickdata();
};

ERQuickdata::ERQuickdata() {
    m_field14 = 0;
    m_vt = (void*)vt_ERQuickdata;
    m_field18 = 0;
}
