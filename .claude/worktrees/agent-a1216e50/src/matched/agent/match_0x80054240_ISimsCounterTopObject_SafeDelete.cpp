/* ISimsCounterTopObject::SafeDelete(void) - 0x80054240 (64 bytes) */

struct ISimsCounterTopObject {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~ISimsCounterTopObject();
    static void SafeDelete(ISimsCounterTopObject *p);
};

void ISimsCounterTopObject::SafeDelete(ISimsCounterTopObject *p)
{
    if (p) {
        delete p;
    }
}
