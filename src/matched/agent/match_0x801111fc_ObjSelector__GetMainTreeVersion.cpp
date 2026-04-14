// 0x801111FC ObjSelector::GetMainTreeVersion (104B)

struct TreeVersionProviderVtbl {
    char pad[0x70];
    short adj;
    void* func;
};

struct TreeVersionProvider {
    TreeVersionProviderVtbl* vtable;
};

extern TreeVersionProvider* ObjSelector_GetTreeVersionProvider(void* self);
extern int ObjSelector_ConvertTreeVersion(void* obj, int version);

struct ObjSelector {
    char pad[0x0c];
    void* m_versionObj;
    char pad2[0x78 - 0x0c - 4];
    int m_mainTreeVersion;
    
    int GetMainTreeVersion();
};

int ObjSelector::GetMainTreeVersion() {
    int version = m_mainTreeVersion;
    if (version == -1) {
        TreeVersionProvider* provider = ObjSelector_GetTreeVersionProvider(this);
        TreeVersionProviderVtbl* vt = provider->vtable;
        short adj = vt->adj;
        void* fn = vt->func;
        typedef int (*GetVersionFunc)(void*, int);
        GetVersionFunc f = (GetVersionFunc)fn;
        int rawVersion = f((char*)provider + adj, 1);
        version = ObjSelector_ConvertTreeVersion(m_versionObj, rawVersion);
        m_mainTreeVersion = version;
    }
    return m_mainTreeVersion;
}
