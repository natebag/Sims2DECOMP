class EController {
public:
    char m_pad[432];
    unsigned int m_fakeButtons;
    void SetFakeButtons(unsigned int);
};
void EController::SetFakeButtons(unsigned int buttons) { m_fakeButtons = buttons; }
