/* REffectsSequencer::SafeDelete(void) - 0x8036B120 (64 bytes) */

struct REffectsSequencer {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~REffectsSequencer();
    static void SafeDelete(REffectsSequencer *p);
};

void REffectsSequencer::SafeDelete(REffectsSequencer *p)
{
    if (p) {
        delete p;
    }
}
