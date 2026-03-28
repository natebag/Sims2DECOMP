/* IShrubObject::IShrubObject(void) at 0x800525E4 (72B) */

extern int IShrubObject_vtable2[];
extern int IShrubObject_vtable[];

struct ISimsObjectModel {
    ISimsObjectModel(void);
};

struct IShrubObject : ISimsObjectModel {
    char pad[0x320 - 4];
    int *m_vtable2;

    IShrubObject(void);
};

IShrubObject::IShrubObject(void) : ISimsObjectModel() {
    m_vtable2 = IShrubObject_vtable2;
    *(int **)this = IShrubObject_vtable;
}
