// 0x80089938 (40B) CreateASimBaseState::CASCanceled(void)
// Returns true if field at +0x20 is null AND field at +0x2c is non-null.

struct CreateASimBaseState {
    char _pad[0x20];
    void* m_field_20;
    char _pad2[0x8];
    void* m_field_2c;
    bool CASCanceled();
};

bool CreateASimBaseState::CASCanceled() {
    return m_field_20 == 0 && m_field_2c != 0;
}
