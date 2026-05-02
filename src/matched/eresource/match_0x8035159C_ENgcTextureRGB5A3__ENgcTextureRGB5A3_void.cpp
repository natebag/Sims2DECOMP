// 0x8035159C (72B) ENgcTextureRGB5A3::ENgcTextureRGB5A3(void)
// SI ctor — ENgcTextureBase(5,4,4) base call + explicit vtable at +0x24.

extern char vt_ENgcTextureRGB5A3[];

class ENgcTextureBase {
public:
    void* m_base_vt;
    ENgcTextureBase(unsigned int format, int w, int h);
};

class ENgcTextureRGB5A3 : public ENgcTextureBase {
public:
    char pad[0x24 - 4];
    void* m_vt_at_24;
    ENgcTextureRGB5A3();
};

ENgcTextureRGB5A3::ENgcTextureRGB5A3() : ENgcTextureBase(5, 4, 4) {
    m_vt_at_24 = (void*)vt_ENgcTextureRGB5A3;
}
