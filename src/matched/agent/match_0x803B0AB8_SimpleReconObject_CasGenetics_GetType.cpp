// SimpleReconObject<CasGenetics>::GetType(void)
// Address: 0x803B0AB8 | Size: 8 bytes
// Pattern: Simple field getter at offset 8

struct SimpleReconObject_CasGenetics {
    char pad[8];
    int m_type;  // at offset 8
};

extern "C" int SimpleReconObject_CasGenetics_GetType(SimpleReconObject_CasGenetics* this_) {
    return this_->m_type;
}
