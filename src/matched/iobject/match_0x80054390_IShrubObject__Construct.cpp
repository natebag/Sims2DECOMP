// 0x80054390 (32 bytes) - IShrubObject::Construct(IShrubObject *)
// Placement-new trampoline.
// FLAGS: -fno-schedule-insns

typedef unsigned int size_t;

class IShrubObject {
public:
    IShrubObject();
    static void Construct(IShrubObject* obj);
};

inline void* operator new(size_t, void* p) { return p; }

void IShrubObject::Construct(IShrubObject* obj) {
    new (obj) IShrubObject();
}
