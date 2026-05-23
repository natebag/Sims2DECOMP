// 0x8005421C (36 bytes) - ISimsCounterTopObject::Destruct(ISimsCounterTopObject *)
// In-place dtor trampoline.
// FLAGS: -fno-schedule-insns

class ISimsCounterTopObject {
public:
    void __dt(int flag);
    static void Destruct(ISimsCounterTopObject* obj);
};

void ISimsCounterTopObject::Destruct(ISimsCounterTopObject* obj) {
    obj->__dt(2);
}
