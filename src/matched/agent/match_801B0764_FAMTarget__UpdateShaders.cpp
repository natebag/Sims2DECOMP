class FAMTarget {
public:
    char _pad[0x88];
    int m_state;

    void UpdateShaders(void);
    void UpdateLotSelectShaders(void);
    void UpdateFamilySelectShaders(void);
    void UpdateOccupiedShaders(void);
};

void FAMTarget::UpdateShaders(void) {
    if (m_state == 0) {
        UpdateLotSelectShaders();
    } else if (m_state == 4) {
        UpdateFamilySelectShaders();
    } else if (m_state == 1) {
        UpdateOccupiedShaders();
    }
}
