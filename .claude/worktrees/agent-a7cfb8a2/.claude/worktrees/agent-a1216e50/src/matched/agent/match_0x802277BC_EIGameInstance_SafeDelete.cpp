/* EIGameInstance::SafeDelete(void) - 0x802277BC (64 bytes) */

struct EIGameInstance {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EIGameInstance();
    static void SafeDelete(EIGameInstance *p);
};

void EIGameInstance::SafeDelete(EIGameInstance *p)
{
    if (p) {
        delete p;
    }
}
