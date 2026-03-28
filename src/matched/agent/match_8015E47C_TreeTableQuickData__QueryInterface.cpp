class TreeTableQuickData {
public:
    int QueryInterface(unsigned int iid, void **ppv);
    virtual void Release();
    virtual void AddRef();
};

int TreeTableQuickData::QueryInterface(unsigned int iid, void **ppv) {
    if (ppv != 0) {
        if (iid == 1 || iid == 0x6BF32230) {
            AddRef();
            *ppv = this;
            return 1;
        }
    }
    return 0;
}
