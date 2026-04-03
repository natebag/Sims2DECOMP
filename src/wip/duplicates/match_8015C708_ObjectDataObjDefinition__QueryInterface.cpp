class ObjectDataObjDefinition {
public:
    int QueryInterface(unsigned int iid, void **ppv);
    virtual void Release();
    virtual void AddRef();
};

int ObjectDataObjDefinition::QueryInterface(unsigned int iid, void **ppv) {
    if (ppv != 0) {
        if (iid == 1 || iid == 0x4BFB20D4) {
            AddRef();
            *ppv = this;
            return 1;
        }
    }
    return 0;
}
