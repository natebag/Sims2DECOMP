/* ISimsMultiTileObjectModel::SafeDelete(void) - 0x800540AC (64 bytes) */

struct ISimsMultiTileObjectModel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~ISimsMultiTileObjectModel();
    static void SafeDelete(ISimsMultiTileObjectModel *p);
};

void ISimsMultiTileObjectModel::SafeDelete(ISimsMultiTileObjectModel *p)
{
    if (p) {
        delete p;
    }
}
