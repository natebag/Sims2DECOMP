// SimpleReconObject<OptionsRecon>::~SimpleReconObject(void)
// Address: 0x803A04D8 | Size: 32 bytes
// Pattern: Wrapper destructor calling base dtor at 0x80134734

struct SimpleReconObject_OptionsRecon {
    void* vtable;
};

// Forward declaration of base destructor
extern "C" void SimpleReconObject_Base_dtor(void* obj);

extern "C" void SimpleReconObject_OptionsRecon_dtor(SimpleReconObject_OptionsRecon* this_) {
    SimpleReconObject_Base_dtor(this_);
}
