// 0x80351700 (72B) ENgcTextureRGBA8::ENgcTextureRGBA8(void)
// SI ctor — ENgcTextureBase(6,4,4) base call + explicit vtable at +0x24.

extern char vt_ENgcTextureRGBA8[];

class ENgcTextureBase {
public:
    void* m_base_vt;
    ENgcTextureBase(unsigned int format, int w, int h);
};

class ENgcTextureRGBA8 : public ENgcTextureBase {
public:
    char pad[0x24 - 4];
    void* m_vt_at_24;
    ENgcTextureRGBA8();
};

ENgcTextureRGBA8::ENgcTextureRGBA8() : ENgcTextureBase(6, 4, 4) {
    m_vt_at_24 = (void*)vt_ENgcTextureRGBA8;
}
