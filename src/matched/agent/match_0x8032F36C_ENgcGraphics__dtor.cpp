// 0x8032F36C (48B) ENgcGraphics::~ENgcGraphics(void)
// Reset vtable to ENgcGraphics's own (pre-base-dtor), then forward to base dtor.

class EGraphics {
public:
    virtual void _vtfiller() = 0;
    ~EGraphics();
};

extern char s_ENgcGraphics_vtable[];   // at 0x8047C4E8

class ENgcGraphics : public EGraphics {
public:
    virtual void _vtfiller() {}
    ~ENgcGraphics();
};

ENgcGraphics::~ENgcGraphics() {
    *(void**)this = s_ENgcGraphics_vtable;
}
