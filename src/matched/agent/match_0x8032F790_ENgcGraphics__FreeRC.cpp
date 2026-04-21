// 0x8032F790 (76B) ENgcGraphics::FreeRC(ERC *, RCMode)
// Guarded MI vcall — only free when mode == 1. Null-guarded vcall through
// vtable at offset 112, slot 1 (8B delta, 12B fn) = Release(int).

enum RCMode {};

class ERCData {
protected:
    char pad[112];
};

class ERC : public ERCData {
public:
    virtual void Release(int flags) = 0;
};

class ENgcGraphics {
public:
    void FreeRC(ERC* rc, RCMode mode);
};

void ENgcGraphics::FreeRC(ERC* rc, RCMode mode) {
    if (mode != (RCMode)1) return;
    if (!rc) return;
    rc->Release(3);
}
