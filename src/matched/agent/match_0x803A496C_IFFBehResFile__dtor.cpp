// 0x803A496C (56B) IFFBehResFile::~IFFBehResFile(void)
// Variant L: non-deleting dtor — two vtable updates (at +0x134 and +0xc) + parent ~IFFResFile2.

extern char vt_IFFBehResFile_a[];
extern char vt_IFFBehResFile_b[];

void IFFResFile2_dtor(void* obj);

struct IFFBehResFile {
    char pad_00_0b[12];
    void* m_vt_at_0c;
    char pad_10_133[292];
    void* m_vt_at_134;
    void dtor();
};

void IFFBehResFile::dtor() {
    m_vt_at_134 = vt_IFFBehResFile_a;
    m_vt_at_0c = vt_IFFBehResFile_b;
    IFFResFile2_dtor(this);
}
