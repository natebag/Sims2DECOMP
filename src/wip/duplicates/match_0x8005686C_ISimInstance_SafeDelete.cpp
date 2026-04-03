/* ISimInstance::SafeDelete(void) - 0x8005686C (64 bytes) */

struct ISimInstance {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~ISimInstance();
    static void SafeDelete(ISimInstance *p);
};

void ISimInstance::SafeDelete(ISimInstance *p)
{
    if (p) {
        delete p;
    }
}
