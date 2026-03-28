class H2DTarget {
public:
    void IncPause(bool pause);
};

class HUDTarget {
public:
    char _pad[0x8B4];
    H2DTarget* m_h2dTarget;

    void IncPause(bool pause);
};

void HUDTarget::IncPause(bool pause) {
    if (m_h2dTarget != 0) {
        m_h2dTarget->IncPause(pause);
    }
}
