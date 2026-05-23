// 0x800543B0 (36 bytes) - IShrubObject::Destruct(IShrubObject *)
// In-place dtor trampoline.
// FLAGS: -fno-schedule-insns

class IShrubObject {
public:
    void __dt(int flag);
    static void Destruct(IShrubObject* obj);
};

void IShrubObject::Destruct(IShrubObject* obj) {
    obj->__dt(2);
}
