class H2DTarget {
public:
    void ReleasePause(bool pause);
};

class HUDTarget {
public:
    char _pad[0x8B4];
    H2DTarget* m_h2dTarget;

    void ReleasePause(bool pause);
};

void HUDTarget::ReleasePause(bool pause) {
    if (m_h2dTarget != 0) {
        m_h2dTarget->ReleasePause(pause);
    }
}
