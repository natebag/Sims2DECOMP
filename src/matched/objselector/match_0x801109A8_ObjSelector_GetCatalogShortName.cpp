// ObjSelector::GetCatalogShortName(void) at 0x801109A8 (92B)
// Template cracked via PMF-via-vtable pattern

class ObjSelector;

struct CatalogVtable {
    char pad[0x28];
    short m_shortOffset;    // +0x28
    int (*m_shortFn)(ObjSelector *, ...);  // +0x2c
};

struct CatalogResource {
    CatalogVtable *m_vt;
};

class ObjSelector {
public:
    ObjSelector *GetMasterSelector();
    CatalogResource *GetCatalogResource();
    ObjSelector *GetCatalogShortName(ObjSelector &other);
};

ObjSelector *ObjSelector::GetCatalogShortName(ObjSelector &other) {
    CatalogResource *res = other.GetMasterSelector()->GetCatalogResource();
    CatalogVtable *vt = res->m_vt;
    ((int (*)(ObjSelector *, ...))vt->m_shortFn)(this, (char *)res + vt->m_shortOffset);
    return this;
}
