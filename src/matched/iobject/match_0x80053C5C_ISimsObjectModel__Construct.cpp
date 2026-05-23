// 0x80053C5C (32 bytes) - ISimsObjectModel::Construct(ISimsObjectModel *)
// Placement-new trampoline that invokes the no-arg ctor on caller-provided
// memory. Used by the EA reflection system to construct objects in-place.
// FLAGS: -fno-schedule-insns

typedef unsigned int size_t;

class ISimsObjectModel {
public:
    ISimsObjectModel();
    static void Construct(ISimsObjectModel* obj);
};

inline void* operator new(size_t, void* p) { return p; }

void ISimsObjectModel::Construct(ISimsObjectModel* obj) {
    new (obj) ISimsObjectModel();
}
