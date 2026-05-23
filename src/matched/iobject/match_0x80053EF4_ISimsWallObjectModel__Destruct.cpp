// 0x80053EF4 (36 bytes) - ISimsWallObjectModel::Destruct(ISimsWallObjectModel *)
// In-place dtor trampoline.
// FLAGS: -fno-schedule-insns

class ISimsWallObjectModel {
public:
    void __dt(int flag);
    static void Destruct(ISimsWallObjectModel* obj);
};

void ISimsWallObjectModel::Destruct(ISimsWallObjectModel* obj) {
    obj->__dt(2);
}
