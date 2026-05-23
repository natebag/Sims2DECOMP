// 0x80054088 (36 bytes) - ISimsMultiTileObjectModel::Destruct(ISimsMultiTileObjectModel *)
// In-place dtor trampoline.
// FLAGS: -fno-schedule-insns

class ISimsMultiTileObjectModel {
public:
    void __dt(int flag);
    static void Destruct(ISimsMultiTileObjectModel* obj);
};

void ISimsMultiTileObjectModel::Destruct(ISimsMultiTileObjectModel* obj) {
    obj->__dt(2);
}
