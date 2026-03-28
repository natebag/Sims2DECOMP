/* REffectsEmitter::SafeDelete(void) - 0x8036ABF0 (64 bytes) */

struct REffectsEmitter {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~REffectsEmitter();
    static void SafeDelete(REffectsEmitter *p);
};

void REffectsEmitter::SafeDelete(REffectsEmitter *p)
{
    if (p) {
        delete p;
    }
}
