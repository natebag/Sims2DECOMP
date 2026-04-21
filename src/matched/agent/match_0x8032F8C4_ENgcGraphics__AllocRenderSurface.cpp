// 0x8032F8C4 (40B) ENgcGraphics::AllocRenderSurface(void)
// `new ENgcRenderSurface()` — 44B object via __builtin_new + default ctor.

class ENgcRenderSurface {
public:
    char pad[44];
    ENgcRenderSurface();
};

class ENgcGraphics {
public:
    ENgcRenderSurface* AllocRenderSurface();
};

ENgcRenderSurface* ENgcGraphics::AllocRenderSurface() {
    return new ENgcRenderSurface();
}
