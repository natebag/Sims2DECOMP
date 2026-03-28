class EEngine {
public:
    char m_pad[12];
    int m_bResetAllowed;
    void SetResetAllowed(bool);
};
void EEngine::SetResetAllowed(bool allowed) { m_bResetAllowed = allowed; }
