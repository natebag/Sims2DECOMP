struct DirectInteractor {
    char pad[0x34];
    float m_moveX;
    float m_moveY;
    float m_lookX;
    float m_lookY;

    void OnCommandUpdate(int command, float value);
};

void DirectInteractor::OnCommandUpdate(int command, float value) {
    if (command == 0x12) {
        m_moveX = value;
        return;
    }
    if (command == 0x13) {
        m_moveY = value;
        return;
    }
    if (command == 0x0B) {
        m_lookX = value;
        return;
    }
    if (command == 0x0C) {
        m_lookY = value;
    }
}
