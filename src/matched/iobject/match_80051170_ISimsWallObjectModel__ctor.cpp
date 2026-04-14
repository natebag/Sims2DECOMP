/* ISimsWallObjectModel::ISimsWallObjectModel(void) at 0x80051170 (72B) */

extern int ISimsWallObjectModel_vtable2[];
extern int ISimsWallObjectModel_vtable[];

struct ISimsObjectModel {
    ISimsObjectModel(void);
};

struct ISimsWallObjectModel : ISimsObjectModel {
    char pad[0x320 - 4];
    int *m_vtable2;

    ISimsWallObjectModel(void);
};

ISimsWallObjectModel::ISimsWallObjectModel(void) : ISimsObjectModel() {
    m_vtable2 = ISimsWallObjectModel_vtable2;
    *(int **)this = ISimsWallObjectModel_vtable;
}
