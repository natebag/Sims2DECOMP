/* EAnimNodeDataPos::SafeDelete(void) - 0x803C97C0 (64 bytes) */

struct EAnimNodeDataPos {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EAnimNodeDataPos();
    static void SafeDelete(EAnimNodeDataPos *p);
};

void EAnimNodeDataPos::SafeDelete(EAnimNodeDataPos *p)
{
    if (p) {
        delete p;
    }
}
