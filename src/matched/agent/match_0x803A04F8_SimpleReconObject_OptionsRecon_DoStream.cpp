// 0x803A04F8 SimpleReconObject<OptionsRecon>::DoStream (36b)

struct SimpleReconObject_OptionsRecon {
    void* vtable;
    void* m_data;  // at offset 4
};

extern "C" void ReconStreamHandler_OptionsRecon(void* data, void* buffer, int size);

void SimpleReconObject_OptionsRecon_DoStream(SimpleReconObject_OptionsRecon* this_, void* buffer, int size) {
    ReconStreamHandler_OptionsRecon(this_->m_data, buffer, size);
}

extern "C" void _ZN17SimpleReconObjectI12OptionsReconE8DoStreamEP11ReconBufferi(SimpleReconObject_OptionsRecon* this_, void* buffer, int size) {
    SimpleReconObject_OptionsRecon_DoStream(this_, buffer, size);
}
