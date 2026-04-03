// ObjSelector::GetCatalogDescription(void) (160 bytes)
// Get catalog description string

class ObjSelector {
public:
    ObjSelector *GetMasterSelector();
    int GetCatalogResource();
};

int ObjSelector::GetCatalogDescription(void) {
    ObjSelector *master = GetMasterSelector();
    int catalogRes = master->GetCatalogResource();

    // Virtual call at offset 32 in vtable
    int result = 0;
    if (catalogRes != 0) {
        int (*fn)(int) = (int (*)(int))(*(int**)catalogRes)[2];
        if (fn != 0) {
            result = fn(catalogRes);
        }
    }
    return result;
}
