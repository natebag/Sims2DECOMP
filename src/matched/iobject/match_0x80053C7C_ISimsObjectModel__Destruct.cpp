// 0x80053C7C (36 bytes) - ISimsObjectModel::Destruct(ISimsObjectModel *)
// In-place dtor trampoline; passes flag=2 to GCC's __dt thunk (in-place,
// don't free). Used by the EA reflection system to destroy objects in
// caller-owned memory.
// FLAGS: -fno-schedule-insns

class ISimsObjectModel {
public:
    void __dt(int flag);
    static void Destruct(ISimsObjectModel* obj);
};

void ISimsObjectModel::Destruct(ISimsObjectModel* obj) {
    obj->__dt(2);
}
