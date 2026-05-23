// 0x80053ED4 (32 bytes) - ISimsWallObjectModel::Construct(ISimsWallObjectModel *)
// Placement-new trampoline.
// FLAGS: -fno-schedule-insns

typedef unsigned int size_t;

class ISimsWallObjectModel {
public:
    ISimsWallObjectModel();
    static void Construct(ISimsWallObjectModel* obj);
};

inline void* operator new(size_t, void* p) { return p; }

void ISimsWallObjectModel::Construct(ISimsWallObjectModel* obj) {
    new (obj) ISimsWallObjectModel();
}
