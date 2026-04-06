

struct TextureBase {
    char data[36];
    virtual ~TextureBase();
    virtual void VFunc1();
    virtual void Lock();
    virtual void Unlock();
    virtual void Invalidate();
    virtual void VFunc5();
    virtual void UpdateBegin();
    virtual void UpdateMipLevel();
    virtual void UpdatePalette();
    virtual void UpdatePaletteDeswizzled();
    virtual void ClearTileFlags();
    virtual void ClearSwizzleFlag();
    virtual void SetSwizzleFlag();
    virtual void UpdateEnd();
    virtual void VFunc14();
    virtual void VFunc15();
    virtual void VFunc16();
    virtual int GetTEVStageCount();
    virtual int GetTEXCount();
    virtual void Select();
};

struct ENgcTexture {
    char pad[40];
    TextureBase* base;
};

int ENgcTexture_GetTEVStageCount(ENgcTexture* self) {
    return self->base->GetTEVStageCount();
}
