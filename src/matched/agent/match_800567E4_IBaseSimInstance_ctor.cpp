// 0x800567E4 (20 bytes) - IBaseSimInstance::IBaseSimInstance(void)
// Sets vtable pointer only, no field initialization

struct IBaseSimInstance_ctor {
    virtual void dummy();
    IBaseSimInstance_ctor();
};

IBaseSimInstance_ctor::IBaseSimInstance_ctor() {}
