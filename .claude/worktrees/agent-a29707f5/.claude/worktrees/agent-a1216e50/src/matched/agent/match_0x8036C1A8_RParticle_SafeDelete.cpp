/* RParticle::SafeDelete(void) - 0x8036C1A8 (64 bytes) */

struct RParticle {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~RParticle();
    static void SafeDelete(RParticle *p);
};

void RParticle::SafeDelete(RParticle *p)
{
    if (p) {
        delete p;
    }
}
