class MODTarget {
public:
    void DisplayFastForward(void);
};

class H2DTarget {
public:
    char _pad[0x88];
    MODTarget *m_modTargets[2];

    void DisplayFastForward(void);
};

void H2DTarget::DisplayFastForward(void) {
    if (m_modTargets[0] != 0) {
        m_modTargets[0]->DisplayFastForward();
    }
}
