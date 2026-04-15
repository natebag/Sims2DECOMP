// ObjSelector::GetCatalogName(void) at 0x801108F0 (92B)
// Template cracked via PMF-via-vtable pattern (see CTGFileImpl::WriteFloat)

class ObjSelector;

struct CatalogVtable {
    char pad[0x18];
    short m_nameOffset;    // +0x18
    int (*m_nameFn)(ObjSelector *, ...);  // +0x1c
};

struct CatalogResource {
    CatalogVtable *m_vt;
};

class ObjSelector {
public:
    ObjSelector *GetMasterSelector();
    CatalogResource *GetCatalogResource();
    ObjSelector *GetCatalogName(ObjSelector &other);
};

ObjSelector *ObjSelector::GetCatalogName(ObjSelector &other) {
    CatalogResource *res = other.GetMasterSelector()->GetCatalogResource();
    CatalogVtable *vt = res->m_vt;
    ((int (*)(ObjSelector *, ...))vt->m_nameFn)(this, (char *)res + vt->m_nameOffset);
    return this;
}
