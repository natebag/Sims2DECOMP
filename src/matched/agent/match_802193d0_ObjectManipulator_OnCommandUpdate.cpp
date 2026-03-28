struct ObjectManipulator_CU {
    char pad[0x34];
    float m_stickX;
    float m_stickY;
    float m_lookX;
    float m_lookY;

    void OnCommandUpdate(int command, float value);
};

void ObjectManipulator_CU::OnCommandUpdate(int command, float value) {
    switch (command) {
        case 7:
            m_stickX = value;
            break;
        case 8:
            m_stickY = value;
            break;
        case 0x0B:
            m_lookX = value;
            break;
        case 0x0C:
            m_lookY = value;
            break;
    }
}
