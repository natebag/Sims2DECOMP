// ObjSelector::GetCatalogShortName(void) (160 bytes)
// Get catalog short name string

class ObjSelector {
public:
    ObjSelector *GetMasterSelector();
    int GetCatalogResource();
};

int ObjSelector::GetCatalogShortName(void) {
    ObjSelector *master = GetMasterSelector();
    int catalogRes = master->GetCatalogResource();

    // Virtual call at offset 40 in vtable
    int result = 0;
    if (catalogRes != 0) {
        int (*fn)(int) = (int (*)(int))(*(int**)catalogRes)[3];
        if (fn != 0) {
            result = fn(catalogRes);
        }
    }
    return result;
}
