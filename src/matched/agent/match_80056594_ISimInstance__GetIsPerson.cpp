// ISimInstance::GetIsPerson(void)
// Address: 0x80056594 | Size: 76 bytes
// cmpwi r11, 0; bne (vtable_call); li r3, 0; b return;
// vtable_call: dispatch through vtable+0x368/0x36C, then ObjSelector::GetIsPerson

struct ObjSelector;
int ObjSelector__GetIsPerson(ObjSelector *sel);  // 0x80111170

struct cXObject;

class ISimInstance {
public:
    char _pad[0x328];
    cXObject *m_xob;  // offset 0x328

    int GetIsPerson(void);
};

int ISimInstance::GetIsPerson(void) {
    cXObject *r11 = m_xob;
    if (r11 != 0) {
        // Virtual dispatch through vtable at r11+4
        int *vtbl = *(int **)((char *)r11 + 4);
        short adj = *(short *)((char *)vtbl + 0x368);
        ObjSelector *(*fn)(void *) = (ObjSelector *(*)(void *))*(void **)((char *)vtbl + 0x36C);
        ObjSelector *sel = fn((char *)r11 + adj);
        return ObjSelector__GetIsPerson(sel);
    }
    return 0;
}
