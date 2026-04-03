struct EController {
    char _pad[0x1ac];
    int m_controlFake;
    void SetControlFake(int val);
};
void EController::SetControlFake(int val) { m_controlFake = val; }
