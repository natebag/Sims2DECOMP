/* XObjLang::XObjLang(ObjSelector *) at 0x80152390 (20B) */

extern int __vt_8XObjLang[];

struct XObjLang {
    int* m_vtable;
    void* m_selector;
    XObjLang(void* sel);
};

XObjLang::XObjLang(void* sel) {
    m_vtable = __vt_8XObjLang;
    m_selector = sel;
}
