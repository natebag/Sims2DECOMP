// 0x80350C84 (72B) ENgcTextureC8::ENgcTextureC8(void)
// SI ctor — ENgcTextureBase(9,8,4) base call + explicit vtable at +0x24.

extern char vt_ENgcTextureC8[];

class ENgcTextureBase {
public:
    void* m_base_vt;
    ENgcTextureBase(unsigned int format, int w, int h);
};

class ENgcTextureC8 : public ENgcTextureBase {
public:
    char pad[0x24 - 4];
    void* m_vt_at_24;
    ENgcTextureC8();
};

ENgcTextureC8::ENgcTextureC8() : ENgcTextureBase(9, 8, 4) {
    m_vt_at_24 = (void*)vt_ENgcTextureC8;
}
