// 0x800F9A10 (36B) ObjectModuleImpl::IsBuyAndBuildDisabled(void) — MI-vcall

struct ObjectModuleImpl;

struct IObjectModule {
public:
    virtual int GetSimFlag(int, int) = 0;  // filler slot 0
    virtual int IsBuyAndBuildDisabled(void) = 0;  // slot 1 — the actual method
};

struct ObjectModuleImpl {
public:
    IObjectModule* m_impl;

    virtual int GetSimFlag(int a, int b) {
        return m_impl->GetSimFlag(a, b);
    }

    virtual int IsBuyAndBuildDisabled(void) {
        return m_impl->IsBuyAndBuildDisabled();
    }
};
