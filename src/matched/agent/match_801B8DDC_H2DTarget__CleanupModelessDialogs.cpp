class MDITarget {
public:
    void CleanupModelessDialogs();
};

class H2DTarget {
public:
    char _pad[0xC8];
    MDITarget *m_mdiTarget;

    void CleanupModelessDialogs();
};

void H2DTarget::CleanupModelessDialogs() {
    if (m_mdiTarget != 0) {
        m_mdiTarget->CleanupModelessDialogs();
    }
}
