/* ISimsWallObjectModel::SafeDelete(void) - 0x80053F18 (64 bytes) */

struct ISimsWallObjectModel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~ISimsWallObjectModel();
    static void SafeDelete(ISimsWallObjectModel *p);
};

void ISimsWallObjectModel::SafeDelete(ISimsWallObjectModel *p)
{
    if (p) {
        delete p;
    }
}
