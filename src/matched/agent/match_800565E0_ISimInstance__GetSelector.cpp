// ISimInstance::GetSelector(void)
// Address: 0x800565E0 | Size: 72 bytes
// Same pattern as GetIsPerson but no post-call to ObjSelector::GetIsPerson
// Returns ObjSelector* directly (or NULL if m_xob is null)

struct ObjSelector;
struct cXObject;

class ISimInstance {
public:
    char _pad[0x328];
    cXObject *m_xob;  // offset 0x328

    ObjSelector *GetSelector(void);
};

ObjSelector *ISimInstance::GetSelector(void) {
    cXObject *r11 = m_xob;
    if (r11 != 0) {
        // Virtual dispatch through vtable at r11+4
        int *vtbl = *(int **)((char *)r11 + 4);
        short adj = *(short *)((char *)vtbl + 0x368);
        ObjSelector *(*fn)(void *) = (ObjSelector *(*)(void *))*(void **)((char *)vtbl + 0x36C);
        return fn((char *)r11 + adj);
    }
    return 0;
}
