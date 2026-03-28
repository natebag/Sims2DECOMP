class MODTarget {
public:
    void DisplayFastForward();
};

class H2DTarget {
public:
    char _pad[0x88];
    MODTarget *m_modTarget;

    void DisplayFastForward();
};

void H2DTarget::DisplayFastForward() {
    if (m_modTarget != 0) {
        m_modTarget->DisplayFastForward();
    }
}
