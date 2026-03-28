class MDITarget {
public:
    int CountModelessDialogs();
};

class H2DTarget {
public:
    char _pad[0xC8];
    MDITarget *m_mdiTarget;

    int CountModelessDialogs(void);
};

int H2DTarget::CountModelessDialogs(void) {
    if (m_mdiTarget != 0) {
        return m_mdiTarget->CountModelessDialogs();
    }
    return 0;
}
