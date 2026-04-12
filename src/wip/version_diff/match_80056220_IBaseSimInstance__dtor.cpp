// 0x80056220 IBaseSimInstance::~IBaseSimInstance (52b)

struct IBaseSimInstance {
    void** _vtable;
    
    virtual ~IBaseSimInstance();
};

extern void* g_vtable_IBaseSimInstance[];
extern void FreeImpl(void*);

IBaseSimInstance::~IBaseSimInstance() {
    _vtable = g_vtable_IBaseSimInstance;
}
