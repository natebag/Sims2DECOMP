/* EInstance::SafeDelete(void) - 0x80229360 (64 bytes) */

struct EInstance {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EInstance();
    static void SafeDelete(EInstance *p);
};

void EInstance::SafeDelete(EInstance *p)
{
    if (p) {
        delete p;
    }
}
