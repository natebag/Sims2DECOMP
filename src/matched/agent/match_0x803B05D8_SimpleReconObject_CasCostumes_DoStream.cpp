// SimpleReconObject<CasCostumes>::DoStream(ReconBuffer *, int)
// Address: 0x803B05D8 | Size: 36 bytes
// Pattern: Wrapper loading field at offset 4, then calling handler

struct SimpleReconObject_CasCostumes {
    void* vtable;
    void* m_data;  // at offset 4
};

// Forward declaration of stream handler
extern "C" void ReconStreamHandler(void* data, void* buffer, int size);

extern "C" void SimpleReconObject_CasCostumes_DoStream(SimpleReconObject_CasCostumes* this_, void* buffer, int size) {
    ReconStreamHandler(this_->m_data, buffer, size);
}
