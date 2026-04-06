// SimpleReconObject<OptionsRecon>::GetType(void)
// Address: 0x803A051C | Size: 8 bytes
// Pattern: Simple field getter at offset 8

struct SimpleReconObject_OptionsRecon {
    char pad[8];
    int m_type;  // at offset 8
};

extern "C" int SimpleReconObject_OptionsRecon_GetType(SimpleReconObject_OptionsRecon* this_) {
    return this_->m_type;
}
