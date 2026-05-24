// 0x80304230 EBtnToCmdAssoc::CompareControllerCommands(void) (32 B)
struct EBtnToCmdAssoc {
    unsigned int m_field_0;
    int CompareControllerCommands(const EBtnToCmdAssoc* other);
};
int EBtnToCmdAssoc::CompareControllerCommands(const EBtnToCmdAssoc* other) {
    if (m_field_0 < other->m_field_0) return -1;
    return m_field_0 > other->m_field_0;
}
