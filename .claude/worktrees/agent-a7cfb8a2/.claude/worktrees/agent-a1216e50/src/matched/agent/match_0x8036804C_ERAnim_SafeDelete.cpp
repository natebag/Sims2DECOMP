/* ERAnim::SafeDelete(void) - 0x8036804C (64 bytes) */

struct ERAnim {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~ERAnim();
    static void SafeDelete(ERAnim *p);
};

void ERAnim::SafeDelete(ERAnim *p)
{
    if (p) {
        delete p;
    }
}
