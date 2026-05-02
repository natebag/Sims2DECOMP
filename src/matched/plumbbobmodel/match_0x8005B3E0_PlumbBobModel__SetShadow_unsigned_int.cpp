// 0x8005B3E0 (128B) PlumbBobModel::SetShadow(unsigned int)
// Resource swap with DelRef/AddRef refcounting.
// ASMPROC_swap_cr_field: cr_a=0 cr_b=7 start="cmpwi 7,3,0" end="cmpwi 0,31,0"

struct EResource {
    char vptr_pad[4];
    int m_refCount;
    unsigned int m_id;
    void DelRef();
};

struct EFile;

struct EResourceManager {
    EResource* AddRef(unsigned int id, EFile* file, int flags);
};

extern EResourceManager g_resourceManager __attribute__((section(".data")));

struct PlumbBobModel {
    char pad[0x2c];
    EResource* m_shadow;
    
    unsigned int SetShadow(unsigned int shadowId);
};

unsigned int PlumbBobModel::SetShadow(unsigned int shadowId) {
    EResource* sh = m_shadow;
    unsigned int oldId = 0;
    if (sh != 0) {
        oldId = sh->m_id;
    }
    if (shadowId != oldId) {
        if (sh != 0) {
            sh->DelRef();
            m_shadow = 0;
        }
        if (shadowId != 0) {
            m_shadow = g_resourceManager.AddRef(shadowId, 0, 0);
        }
    }
    return oldId;
}
