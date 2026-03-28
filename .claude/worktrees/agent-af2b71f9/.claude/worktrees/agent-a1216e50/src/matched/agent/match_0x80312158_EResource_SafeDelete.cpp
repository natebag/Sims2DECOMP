/* EResource::SafeDelete(void) - 0x80312158 (64 bytes) */

struct EResource {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EResource();
    static void SafeDelete(EResource *p);
};

void EResource::SafeDelete(EResource *p)
{
    if (p) {
        delete p;
    }
}
