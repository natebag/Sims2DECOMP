/* XObjLang::~XObjLang(void) at 0x801527F4 (48B) */

extern int __vt_8XObjLang[];
extern void BaseDtor(void*);

struct XObjLang {
    int* m_vtable;
    void Destroy();
};

void XObjLang::Destroy() {
    m_vtable = __vt_8XObjLang;
    BaseDtor(this);
}
