class MODTarget {
public:
    void DisplayPaused(void);
};

class H2DTarget {
public:
    char _pad[0x88];
    MODTarget *m_modTargets[2];

    void DisplayPaused(void);
};

void H2DTarget::DisplayPaused(void) {
    if (m_modTargets[0] != 0) {
        m_modTargets[0]->DisplayPaused();
    }
}
