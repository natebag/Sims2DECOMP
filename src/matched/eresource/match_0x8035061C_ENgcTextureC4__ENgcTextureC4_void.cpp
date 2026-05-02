// 0x8035061C (72B) ENgcTextureC4::ENgcTextureC4(void)
// SI ctor — ENgcTextureBase(8,8,8) base call + explicit vtable at +0x24.

extern char vt_ENgcTextureC4[];

class ENgcTextureBase {
public:
    void* m_base_vt;
    ENgcTextureBase(unsigned int format, int w, int h);
};

class ENgcTextureC4 : public ENgcTextureBase {
public:
    char pad[0x24 - 4];
    void* m_vt_at_24;
    ENgcTextureC4();
};

ENgcTextureC4::ENgcTextureC4() : ENgcTextureBase(8, 8, 8) {
    m_vt_at_24 = (void*)vt_ENgcTextureC4;
}
