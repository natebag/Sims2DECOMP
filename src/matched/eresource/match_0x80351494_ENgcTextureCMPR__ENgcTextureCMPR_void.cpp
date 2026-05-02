// 0x80351494 (72B) ENgcTextureCMPR::ENgcTextureCMPR(void)
// SI ctor — ENgcTextureBase(14,8,8) base call + explicit vtable at +0x24.

extern char vt_ENgcTextureCMPR[];

class ENgcTextureBase {
public:
    void* m_base_vt;
    ENgcTextureBase(unsigned int format, int w, int h);
};

class ENgcTextureCMPR : public ENgcTextureBase {
public:
    char pad[0x24 - 4];
    void* m_vt_at_24;
    ENgcTextureCMPR();
};

ENgcTextureCMPR::ENgcTextureCMPR() : ENgcTextureBase(14, 8, 8) {
    m_vt_at_24 = (void*)vt_ENgcTextureCMPR;
}
