// 0x80368278 (72B) ERBinary::ERBinary(void)
// SI ctor — EResource base + 3 stores (vtable + 2 zeros).

extern char vt_ERBinary[];

class EResource {
public:
    void* m_vt;
    EResource();
};

class ERBinary : public EResource {
public:
    char pad04_13[0x14 - 4];
    int m_field14;
    int m_field18;
    ERBinary();
};

ERBinary::ERBinary() {
    m_field14 = 0;
    m_vt = (void*)vt_ERBinary;
    m_field18 = 0;
}
