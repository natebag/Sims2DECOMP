class MODTarget {
public:
    void DisplayPaused();
};

class H2DTarget {
public:
    char _pad[0x88];
    MODTarget *m_modTarget;

    void DisplayPaused();
};

void H2DTarget::DisplayPaused() {
    if (m_modTarget != 0) {
        m_modTarget->DisplayPaused();
    }
}
