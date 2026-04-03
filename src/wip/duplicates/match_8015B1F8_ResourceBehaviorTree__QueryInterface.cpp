class ResourceBehaviorTree {
public:
    int QueryInterface(unsigned int iid, void **ppv);
    virtual void Release();
    virtual void AddRef();
};

int ResourceBehaviorTree::QueryInterface(unsigned int iid, void **ppv) {
    if (ppv != 0) {
        if (iid == 1 || iid == 0x2BEB2426) {
            AddRef();
            *ppv = this;
            return 1;
        }
    }
    return 0;
}
