// 0x80056848 ISimInstance::Destruct (36b)

struct ISimInstance;

extern "C" void ISimInstance_dtor_impl(ISimInstance* self, int flag);

extern "C" void ISimInstance_Destruct(ISimInstance* self) {
    ISimInstance_dtor_impl(self, 2);
}
