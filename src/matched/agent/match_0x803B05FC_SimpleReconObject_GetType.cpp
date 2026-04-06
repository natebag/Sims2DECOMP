// SimpleReconObject<CasCostumes>::GetType(void)
// Address: 0x803B05FC | Size: 8 bytes
// Pattern: Simple field getter at offset 8

struct SimpleReconObject_CasCostumes {
    char pad[8];
    int m_type;  // at offset 8
};

extern "C" int SimpleReconObject_CasCostumes_GetType(SimpleReconObject_CasCostumes* this_) {
    return this_->m_type;
}
