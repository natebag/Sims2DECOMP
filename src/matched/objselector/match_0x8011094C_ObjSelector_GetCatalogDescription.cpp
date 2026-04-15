// ObjSelector::GetCatalogDescription(void) at 0x8011094C (92B)
// Template cracked via PMF-via-vtable pattern

class ObjSelector;

struct CatalogVtable {
    char pad[0x20];
    short m_descOffset;    // +0x20
    int (*m_descFn)(ObjSelector *, ...);  // +0x24
};

struct CatalogResource {
    CatalogVtable *m_vt;
};

class ObjSelector {
public:
    ObjSelector *GetMasterSelector();
    CatalogResource *GetCatalogResource();
    ObjSelector *GetCatalogDescription(ObjSelector &other);
};

ObjSelector *ObjSelector::GetCatalogDescription(ObjSelector &other) {
    CatalogResource *res = other.GetMasterSelector()->GetCatalogResource();
    CatalogVtable *vt = res->m_vt;
    ((int (*)(ObjSelector *, ...))vt->m_descFn)(this, (char *)res + vt->m_descOffset);
    return this;
}
