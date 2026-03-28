/* EIFenceWall::SafeDelete(void) - 0x800306D8 (64 bytes) */

struct EIFenceWall {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EIFenceWall();
    static void SafeDelete(EIFenceWall *p);
};

void EIFenceWall::SafeDelete(EIFenceWall *p)
{
    if (p) {
        delete p;
    }
}
