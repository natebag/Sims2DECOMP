// SimpleReconObject<OptionsRecon>::DoStream(ReconBuffer *, int)
// Address: 0x803A04F8 | Size: 36 bytes
// Pattern: Wrapper loading field at offset 4, then calling handler

struct SimpleReconObject_OptionsRecon {
    void* vtable;
    void* m_data;  // at offset 4
};

// Forward declaration of stream handler
extern "C" void ReconStreamHandler_OptionsRecon(void* data, void* buffer, int size);

extern "C" void SimpleReconObject_OptionsRecon_DoStream(SimpleReconObject_OptionsRecon* this_, void* buffer, int size) {
    ReconStreamHandler_OptionsRecon(this_->m_data, buffer, size);
}
