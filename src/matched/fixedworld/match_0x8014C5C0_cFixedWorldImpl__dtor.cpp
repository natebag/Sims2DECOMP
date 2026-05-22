// 0x8014C5C0 cFixedWorldImpl::~cFixedWorldImpl(void) (112B)

extern int cFixedWorldImpl_vt[];
extern int cFixedWorldImpl_Commander_vt[];
extern int cFixedWorldImpl_dyn_vt[];   // 0x804654C8

extern void Commander_dtor(void* self, int in_charge);
extern void __builtin_delete(void* p);

void cFixedWorldImpl_DeleteArrays(void* self);

class cFixedWorldImpl {
public:
    int* m_vt_primary;       // 0 — primary cFixedWorldImpl vt
    char pad_04[12];
    int* m_vt_commander;     // 16 — Commander vt subobject
};

extern "C" void cFixedWorldImpl_dtor(cFixedWorldImpl* self, int in_charge) {
    char* s = (char*)self;
    *(int**)(s + 16) = cFixedWorldImpl_Commander_vt;
    *(int**)(s + 0) = cFixedWorldImpl_vt;
    cFixedWorldImpl_DeleteArrays(s);
    Commander_dtor(s + 4, 0);
    *(int**)(s + 0) = cFixedWorldImpl_dyn_vt;
    if (in_charge & 1) {
        __builtin_delete(s);
    }
}
