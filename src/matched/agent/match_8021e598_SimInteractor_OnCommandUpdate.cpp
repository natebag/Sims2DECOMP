struct SimInteractor_CU {
    char pad[0x34];
    float m_stickX;
    float m_stickY;
    float m_lookX;
    float m_lookY;

    void OnCommandUpdate(int command, float value);
};

void SimInteractor_CU::OnCommandUpdate(int command, float value) {
    if (command == 7) {
        m_stickX = value;
        return;
    }
    if (command == 8) {
        m_stickY = value;
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
