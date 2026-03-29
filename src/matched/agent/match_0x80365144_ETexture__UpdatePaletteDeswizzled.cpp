struct ETextureBase {
    char _data[0x24];
};

struct ETexture : public ETextureBase {
    virtual void __vf0();
    virtual void __vf1();
    virtual void __vf2();
    virtual void __vf3();
    virtual void __vf4();
    virtual void __vf5();
    virtual void __vf6();
    virtual void __vf7();
    virtual int UpdatePalette();
    virtual void UpdatePaletteDeswizzled();
};

void ETexture::UpdatePaletteDeswizzled() {
    UpdatePalette();
}
