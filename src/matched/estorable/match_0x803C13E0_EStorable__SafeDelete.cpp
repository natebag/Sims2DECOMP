// EStorable::SafeDelete(void) at 0x803C13E0 (64 bytes)
// MI-vcall SafeDelete template — 5 filler virtuals + dtor at slot 5.
// Same shape as EIWallPart::SafeDelete (Technique #47).

struct EStorable {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EStorable();
    static void SafeDelete(EStorable* p);
};

void EStorable::SafeDelete(EStorable* p)
{
    if (p) {
        delete p;
    }
}
