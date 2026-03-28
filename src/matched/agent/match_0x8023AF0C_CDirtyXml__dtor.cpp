extern int __vt_CDirtyXml[];
extern int __vt_CDirtyXml_inner[];
extern int __vt_CDirtyXml_base[];

void FreeDoc(void*);
void BaseDestructor(void*, int);

struct CDirtyXml {
    int* m_vtable;
    void* m_doc;
    char pad08[0x18];
    int* m_innerVtable;

    void Destroy(int flags);
};

void CDirtyXml::Destroy(int flags) {
    m_innerVtable = __vt_CDirtyXml_inner;
    m_vtable = __vt_CDirtyXml;
    if (m_doc != 0) {
        FreeDoc(m_doc);
    }
    m_innerVtable = __vt_CDirtyXml_base;
    BaseDestructor(this, flags);
}
