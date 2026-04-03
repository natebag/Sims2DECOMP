class IFFBehaviorConstants {
public:
    int QueryInterface(unsigned int iid, void **ppv);
    virtual void Release();
    virtual void AddRef();
};

int IFFBehaviorConstants::QueryInterface(unsigned int iid, void **ppv) {
    if (ppv != 0) {
        if (iid == 1 || iid == 0xEBD8CAB4) {
            AddRef();
            *ppv = this;
            return 1;
        }
    }
    return 0;
}
