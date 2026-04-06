// 0x803B0A94 SimpleReconObject<CasGenetics>::DoStream (36b)

struct SimpleReconObject_CasGenetics {
    void* vtable;
    void* m_data;  // at offset 4
};

extern "C" void ReconStreamHandler_CasGenetics(void* data, void* buffer, int size);

void SimpleReconObject_CasGenetics_DoStream(SimpleReconObject_CasGenetics* this_, void* buffer, int size) {
    ReconStreamHandler_CasGenetics(this_->m_data, buffer, size);
}

extern "C" void _ZN17SimpleReconObjectI12CasGeneticsE8DoStreamEP11ReconBufferi(SimpleReconObject_CasGenetics* this_, void* buffer, int size) {
    SimpleReconObject_CasGenetics_DoStream(this_, buffer, size);
}
