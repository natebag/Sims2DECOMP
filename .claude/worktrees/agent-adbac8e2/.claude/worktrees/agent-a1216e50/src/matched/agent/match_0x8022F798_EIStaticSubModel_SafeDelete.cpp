/* EIStaticSubModel::SafeDelete(void) - 0x8022F798 (64 bytes) */

struct EIStaticSubModel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EIStaticSubModel();
    static void SafeDelete(EIStaticSubModel *p);
};

void EIStaticSubModel::SafeDelete(EIStaticSubModel *p)
{
    if (p) {
        delete p;
    }
}
