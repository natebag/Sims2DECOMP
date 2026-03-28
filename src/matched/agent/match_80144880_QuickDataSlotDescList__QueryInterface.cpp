class QuickDataSlotDescList {
public:
    int QueryInterface(unsigned int iid, void **ppv);
    virtual void Release();
    virtual void AddRef();
};

int QuickDataSlotDescList::QueryInterface(unsigned int iid, void **ppv) {
    if (ppv != 0) {
        if (iid == 1 || iid == 0x2C030753) {
            AddRef();
            *ppv = this;
            return 1;
        }
    }
    return 0;
}
