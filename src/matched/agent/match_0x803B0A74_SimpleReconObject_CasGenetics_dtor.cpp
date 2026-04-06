// SimpleReconObject<CasGenetics>::~SimpleReconObject(void)
// Address: 0x803B0A74 | Size: 32 bytes
// Pattern: Wrapper destructor calling base dtor at 0x80134734

struct SimpleReconObject_CasGenetics {
    void* vtable;
};

// Forward declaration of base destructor
extern "C" void SimpleReconObject_Base_dtor(void* obj);

extern "C" void SimpleReconObject_CasGenetics_dtor(SimpleReconObject_CasGenetics* this_) {
    SimpleReconObject_Base_dtor(this_);
}
