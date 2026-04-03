struct EController {
    char _pad[0x1ac];
    int m_controlFake;
    int IsControlFake();
};
int EController::IsControlFake() { return m_controlFake; }
