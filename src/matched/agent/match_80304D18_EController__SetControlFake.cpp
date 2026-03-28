class EController {
public:
    char m_pad[428];
    int m_controlFake;
    void SetControlFake(bool);
};
void EController::SetControlFake(bool fake) { m_controlFake = fake; }
