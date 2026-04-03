/* IShrubObject::SafeDelete(void) - 0x800543D4 (64 bytes) */

struct IShrubObject {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~IShrubObject();
    static void SafeDelete(IShrubObject *p);
};

void IShrubObject::SafeDelete(IShrubObject *p)
{
    if (p) {
        delete p;
    }
}
