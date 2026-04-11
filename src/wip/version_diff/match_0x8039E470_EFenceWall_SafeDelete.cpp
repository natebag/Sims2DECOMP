/* EFenceWall::SafeDelete(void) - 0x8039E470 (64 bytes) */

struct EFenceWall {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EFenceWall();
    static void SafeDelete(EFenceWall *p);
};

void EFenceWall::SafeDelete(EFenceWall *p)
{
    if (p) {
        delete p;
    }
}
