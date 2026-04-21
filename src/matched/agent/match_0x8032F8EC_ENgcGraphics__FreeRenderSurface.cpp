// 0x8032F8EC (64B) ENgcGraphics::FreeRenderSurface(ERenderSurface *)
// MI vcall: non-virtual 32B base, vtable at offset 32, slot 1 = Release(int).

class ERenderSurfaceData {
protected:
    char pad[32];
};

class ERenderSurface : public ERenderSurfaceData {
public:
    virtual void Release(int flags) = 0;
};

class ENgcGraphics {
public:
    void FreeRenderSurface(ERenderSurface* rs);
};

void ENgcGraphics::FreeRenderSurface(ERenderSurface* rs) {
    if (!rs) return;
    rs->Release(3);
}
