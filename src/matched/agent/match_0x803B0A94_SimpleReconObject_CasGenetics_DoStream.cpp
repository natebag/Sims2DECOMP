// SimpleReconObject<CasGenetics>::DoStream(ReconBuffer *, int)
// Address: 0x803B0A94 | Size: 36 bytes
// Pattern: Wrapper loading field at offset 4, then calling handler

struct SimpleReconObject_CasGenetics {
    void* vtable;
    void* m_data;  // at offset 4
};

// Forward declaration of stream handler
extern "C" void ReconStreamHandler_CasGenetics(void* data, void* buffer, int size);

extern "C" void SimpleReconObject_CasGenetics_DoStream(SimpleReconObject_CasGenetics* this_, void* buffer, int size) {
    ReconStreamHandler_CasGenetics(this_->m_data, buffer, size);
}
