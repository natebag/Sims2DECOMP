struct ObjectManipulator_CR {
    char pad[0x34];
    float m_stickX;
    float m_stickY;
    float m_lookX;
    float m_lookY;

    void OnCommandReleased(int command);
};

void ObjectManipulator_CR::OnCommandReleased(int command) {
    switch (command) {
        case 7:
            m_stickX = 0.0f;
            break;
        case 8:
            m_stickY = 0.0f;
            break;
        case 0x0B:
            m_lookX = 0.0f;
            break;
        case 0x0C:
            m_lookY = 0.0f;
            break;
    }
}
