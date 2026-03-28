/* ISimsCounterTopObject::ISimsCounterTopObject(void) at 0x800520AC (72B) */

extern int ISimsCounterTopObject_vtable2[];
extern int ISimsCounterTopObject_vtable[];

struct ISimsObjectModel {
    ISimsObjectModel(void);
};

struct ISimsCounterTopObject : ISimsObjectModel {
    char pad[0x320 - 4];
    int *m_vtable2;

    ISimsCounterTopObject(void);
};

ISimsCounterTopObject::ISimsCounterTopObject(void) : ISimsObjectModel() {
    m_vtable2 = ISimsCounterTopObject_vtable2;
    *(int **)this = ISimsCounterTopObject_vtable;
}
