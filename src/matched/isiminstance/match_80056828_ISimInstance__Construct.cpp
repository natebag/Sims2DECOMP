// 0x80056828 ISimInstance::Construct (32b)

struct ISimInstance;

extern "C" void ISimInstance_ctor(ISimInstance* self);

extern "C" void ISimInstance_Construct(ISimInstance* self) {
    ISimInstance_ctor(self);
}
