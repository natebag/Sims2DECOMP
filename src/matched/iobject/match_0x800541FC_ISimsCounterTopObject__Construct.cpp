// 0x800541FC (32 bytes) - ISimsCounterTopObject::Construct(ISimsCounterTopObject *)
// Placement-new trampoline.
// FLAGS: -fno-schedule-insns

typedef unsigned int size_t;

class ISimsCounterTopObject {
public:
    ISimsCounterTopObject();
    static void Construct(ISimsCounterTopObject* obj);
};

inline void* operator new(size_t, void* p) { return p; }

void ISimsCounterTopObject::Construct(ISimsCounterTopObject* obj) {
    new (obj) ISimsCounterTopObject();
}
