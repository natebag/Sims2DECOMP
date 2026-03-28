class TreeTableEntryQuickData {
public:
    int QueryInterface(unsigned int iid, void **ppv);
    virtual void Release();
    virtual void AddRef();
};

int TreeTableEntryQuickData::QueryInterface(unsigned int iid, void **ppv) {
    if (ppv != 0) {
        if (iid == 1 || iid == 0x6BF3222B) {
            AddRef();
            *ppv = this;
            return 1;
        }
    }
    return 0;
}
