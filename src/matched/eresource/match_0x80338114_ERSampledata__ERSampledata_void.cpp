// 0x80338114 (72B) ERSampledata::ERSampledata(void)
// SI ctor — EResource base + 3 stores (vtable + 2 zeros).

extern char vt_ERSampledata[];

class EResource {
public:
    void* m_vt;
    EResource();
};

class ERSampledata : public EResource {
public:
    char pad04_13[0x14 - 4];
    int m_field14;
    int m_field18;
    ERSampledata();
};

ERSampledata::ERSampledata() {
    m_field14 = 0;
    m_vt = (void*)vt_ERSampledata;
    m_field18 = 0;
}
