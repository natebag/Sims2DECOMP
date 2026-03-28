class EController {
public:
    char m_pad[428];
    int m_controlFake;
    int IsControlFake();
};
int EController::IsControlFake() { return m_controlFake; }
