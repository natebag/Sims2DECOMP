// 0x800B1C88 CatalogResource::DestroyInstance (64B)

struct CatalogResource {
    virtual ~CatalogResource();
    static void DestroyInstance(CatalogResource *p);
};

void CatalogResource::DestroyInstance(CatalogResource *p) {
    if (p) {
        delete p;
    }
}
