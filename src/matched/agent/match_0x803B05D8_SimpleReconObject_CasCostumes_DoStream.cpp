// 0x803B05D8 SimpleReconObject<CasCostumes>::DoStream (36b)

struct SimpleReconObject_CasCostumes {
    void* vtable;
    void* m_data;  // at offset 4
};

extern "C" void ReconStreamHandler_CasCostumes(void* data, void* buffer, int size);

void SimpleReconObject_CasCostumes_DoStream(SimpleReconObject_CasCostumes* this_, void* buffer, int size) {
    ReconStreamHandler_CasCostumes(this_->m_data, buffer, size);
}

extern "C" void _ZN17SimpleReconObjectI12CasCostumesE8DoStreamEP11ReconBufferi(SimpleReconObject_CasCostumes* this_, void* buffer, int size) {
    SimpleReconObject_CasCostumes_DoStream(this_, buffer, size);
}
