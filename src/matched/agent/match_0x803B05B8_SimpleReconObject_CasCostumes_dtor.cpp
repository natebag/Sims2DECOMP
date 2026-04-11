// SimpleReconObject<CasCostumes>::~SimpleReconObject(void)
// Address: 0x803B05B8 | Size: 32 bytes
// Pattern: Wrapper destructor calling base dtor at 0x80134734

struct SimpleReconObject_CasCostumes {
    void* vtable;
};

// Forward declaration of base destructor
extern "C" void SimpleReconObject_Base_dtor(void* obj);

extern "C" void SimpleReconObject_CasCostumes_dtor(SimpleReconObject_CasCostumes* this_) {
    SimpleReconObject_Base_dtor(this_);
}
