struct OCU_S {
    char _pad[0x34];
    float m_stickLX;
    float m_stickLY;
    float m_stickRX;
    float m_stickRY;

    void OnCommandUpdate(int cmd, float val);
};

void OCU_S::OnCommandUpdate(int cmd, float val) {
    switch (cmd) {
        case 7: m_stickLX = val; break;
        case 8: m_stickLY = val; break;
        case 11: m_stickRX = val; break;
        case 12: m_stickRY = val; break;
    }
}
