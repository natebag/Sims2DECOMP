class EEngine {
public:
    char m_pad[12];
    int m_bResetAllowed;
    int CanReset();
};
int EEngine::CanReset() { return m_bResetAllowed; }
