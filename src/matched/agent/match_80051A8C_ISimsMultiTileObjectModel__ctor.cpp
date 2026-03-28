/* ISimsMultiTileObjectModel::ISimsMultiTileObjectModel(void) at 0x80051A8C (72B) */

extern int ISimsMultiTileObjectModel_vtable2[];
extern int ISimsMultiTileObjectModel_vtable[];

struct ISimsObjectModel {
    ISimsObjectModel(void);
};

struct ISimsMultiTileObjectModel : ISimsObjectModel {
    char pad[0x320 - 4];
    int *m_vtable2;

    ISimsMultiTileObjectModel(void);
};

ISimsMultiTileObjectModel::ISimsMultiTileObjectModel(void) : ISimsObjectModel() {
    m_vtable2 = ISimsMultiTileObjectModel_vtable2;
    *(int **)this = ISimsMultiTileObjectModel_vtable;
}
