// 0x8032F32C (64B) ENgcGraphics::ENgcGraphics(void)
// Call base ctor, install derived vtable at offset 0, register SDA singleton.

class EGraphics {
public:
    virtual void _vtfiller() = 0;
    EGraphics();
};

extern char s_ENgcGraphics_vtable[];   // at 0x8047C4E8

class ENgcGraphics : public EGraphics {
public:
    virtual void _vtfiller() {}   // override
    ENgcGraphics();
};

extern ENgcGraphics* g_ngcGraphics;    // SDA singleton at -26392(r13)

ENgcGraphics::ENgcGraphics() : EGraphics() {
    *(void**)this = s_ENgcGraphics_vtable;
    g_ngcGraphics = this;
}
