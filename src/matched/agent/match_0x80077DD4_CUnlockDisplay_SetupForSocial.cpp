class CUnlockDisplay {
    char pad[1100];
    int m_state;  // offset 1100
public:
    void Setup(void* param);
    void SetupForSocial(void* param);
};

void CUnlockDisplay::SetupForSocial(void* param) {
    this->m_state = 3;
    this->Setup(param);
}
