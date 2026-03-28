struct DirectInteractor_R {
    char pad[0x30];
    int m_commandId;
    float m_moveX;
    float m_moveY;
    float m_lookX;
    float m_lookY;

    void OnCommandReleased(int command);
};

void DirectInteractor_R::OnCommandReleased(int command) {
    if (command == 0) {
        m_commandId = command;
        return;
    }
    if (command == 0x12) {
        m_moveX = 0.0f;
        return;
    }
    if (command == 0x13) {
        m_moveY = 0.0f;
        return;
    }
    if (command == 0x0B) {
        m_lookX = 0.0f;
        return;
    }
    if (command == 0x0C) {
        m_lookY = 0.0f;
    }
}
