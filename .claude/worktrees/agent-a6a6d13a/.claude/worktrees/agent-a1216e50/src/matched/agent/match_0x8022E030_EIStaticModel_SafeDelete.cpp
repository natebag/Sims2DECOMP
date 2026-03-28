/* EIStaticModel::SafeDelete(void) - 0x8022E030 (64 bytes) */

struct EIStaticModel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EIStaticModel();
    static void SafeDelete(EIStaticModel *p);
};

void EIStaticModel::SafeDelete(EIStaticModel *p)
{
    if (p) {
        delete p;
    }
}
