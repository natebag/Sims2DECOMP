struct EController {
    char _pad[0x1b0];
    unsigned int m_fakeButtons;
    void SetFakeButtons(unsigned int val);
};
void EController::SetFakeButtons(unsigned int val) { m_fakeButtons = val; }
