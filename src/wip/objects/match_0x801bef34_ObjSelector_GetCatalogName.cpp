// ObjSelector::GetCatalogName(void) (160 bytes)
// Get catalog name string through master selector and catalog resource

class ObjSelector {
public:
    ObjSelector *GetMasterSelector();
    int GetCatalogResource();  // returns resource interface pointer
    int GetCatalogName_impl(int catalogResource);  // actual GetCatalogName call
};

int ObjSelector::GetCatalogName(void) {
    // Pattern: Get master selector first
    ObjSelector *master = GetMasterSelector();

    // Then get catalog resource from master
    int catalogRes = master->GetCatalogResource();

    // Call GetCatalogName on the catalog resource (offset 24)
    // This is a virtual method call: lwz 9,0(r4); lha 0,24(r9); lwz 9,28(r9)
    int result = 0;
    if (catalogRes != 0) {
        // Call virtual function at offset 24 in vtable
        int (*fn)(int) = (int (*)(int))(*(int**)catalogRes)[1];  // vtable entry 1
        if (fn != 0) {
            result = fn(catalogRes);
        }
    }

    return result;
}
