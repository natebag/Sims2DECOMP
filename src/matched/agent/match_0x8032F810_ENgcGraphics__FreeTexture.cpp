// 0x8032F810 (64B) ENgcGraphics::FreeTexture(ETexture *)
// MI vcall: non-virtual 36B base, then secondary vtable at offset 36.
// Slot 1 of secondary vtable (offset +8 for delta, +12 for fn) = Release(int).

class ETextureData {
protected:
    char pad[36];
};

class ETexture : public ETextureData {
public:
    virtual void Release(int flags) = 0;
};

class ENgcGraphics {
public:
    void FreeTexture(ETexture* tex);
};

void ENgcGraphics::FreeTexture(ETexture* tex) {
    if (!tex) return;
    tex->Release(3);
}
