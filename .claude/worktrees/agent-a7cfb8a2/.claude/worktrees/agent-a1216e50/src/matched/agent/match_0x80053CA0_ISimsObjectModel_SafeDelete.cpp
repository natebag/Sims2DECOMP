/* ISimsObjectModel::SafeDelete(void) - 0x80053CA0 (64 bytes) */

struct ISimsObjectModel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~ISimsObjectModel();
    static void SafeDelete(ISimsObjectModel *p);
};

void ISimsObjectModel::SafeDelete(ISimsObjectModel *p)
{
    if (p) {
        delete p;
    }
}
