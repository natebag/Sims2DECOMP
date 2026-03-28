class SmartDataFactory {
public:
    int QueryInterface(unsigned int iid, void **ppv);
    virtual void Release();
    virtual void AddRef();
};

int SmartDataFactory::QueryInterface(unsigned int iid, void **ppv) {
    if (ppv != 0) {
        if (iid == 1 || iid == 0x0BC37D68) {
            AddRef();
            *ppv = this;
            return 1;
        }
    }
    return 0;
}
