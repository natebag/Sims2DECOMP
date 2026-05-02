// 0x80350750 (84B) ENgcTextureC4_32::ENgcTextureC4_32(void)
// SI ctor — ENgcTextureBase(8,8,8) base call + vtable at +0x24 + 2 zero stores (0xCC, 0xD0).

extern char vt_ENgcTextureC4_32[];

class ENgcTextureBase {
public:
    void* m_base_vt;
    ENgcTextureBase(unsigned int format, int w, int h);
};

class ENgcTextureC4_32 : public ENgcTextureBase {
public:
    char pad[0x24 - 4];
    void* m_vt_at_24;
    char pad28_CB[0xCC - 0x28];
    int m_fieldCC;
    int m_fieldD0;
    ENgcTextureC4_32();
};

ENgcTextureC4_32::ENgcTextureC4_32() : ENgcTextureBase(8, 8, 8) {
    m_fieldCC = 0;
    m_vt_at_24 = (void*)vt_ENgcTextureC4_32;
    m_fieldD0 = 0;
}
