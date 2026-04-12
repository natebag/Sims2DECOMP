// 0x800567E4 IBaseSimInstance::IBaseSimInstance (20b)

extern int IBaseSimInstance_vtable[];

struct IBaseSimInstance {
    int* m_vt;
    IBaseSimInstance();
};

IBaseSimInstance::IBaseSimInstance() {
    *(int**)this = IBaseSimInstance_vtable;
}
