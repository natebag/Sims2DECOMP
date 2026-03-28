/* CatalogResource::DestroyInstance(CatalogResource *) - 0x800B1C88 (64 bytes) */

struct CatalogResource {
    virtual ~CatalogResource();
    static void DestroyInstance(CatalogResource *p);
};

void CatalogResource::DestroyInstance(CatalogResource *p)
{
    if (p) {
        delete p;
    }
}
