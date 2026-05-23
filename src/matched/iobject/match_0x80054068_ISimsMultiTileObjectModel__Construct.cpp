// 0x80054068 (32 bytes) - ISimsMultiTileObjectModel::Construct(ISimsMultiTileObjectModel *)
// Placement-new trampoline.
// FLAGS: -fno-schedule-insns

typedef unsigned int size_t;

class ISimsMultiTileObjectModel {
public:
    ISimsMultiTileObjectModel();
    static void Construct(ISimsMultiTileObjectModel* obj);
};

inline void* operator new(size_t, void* p) { return p; }

void ISimsMultiTileObjectModel::Construct(ISimsMultiTileObjectModel* obj) {
    new (obj) ISimsMultiTileObjectModel();
}
