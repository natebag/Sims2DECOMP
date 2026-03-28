/* ERModel::SafeDelete(void) - 0x8031B264 (64 bytes) */

struct ERModel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~ERModel();
    static void SafeDelete(ERModel *p);
};

void ERModel::SafeDelete(ERModel *p)
{
    if (p) {
        delete p;
    }
}
