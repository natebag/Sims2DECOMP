// 0x80152390 XObjLang::XObjLang (20b)
// FLAGS: -fno-schedule-insns

extern int XObjLang_vtable[];

struct ObjSelector;

struct XObjLang {
    int* m_vt;
    ObjSelector* m_selector;
    XObjLang(ObjSelector* p2);
};

XObjLang::XObjLang(ObjSelector* p2) {
    *(int**)this = XObjLang_vtable;
    m_selector = p2;
}
