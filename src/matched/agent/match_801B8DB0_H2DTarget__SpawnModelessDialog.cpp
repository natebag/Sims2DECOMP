class UIDialog;

class MDITarget {
public:
    void SpawnModelessDialog(UIDialog *dlg);
};

class H2DTarget {
public:
    char _pad[0xC8];
    MDITarget *m_mdiTarget;

    void SpawnModelessDialog(UIDialog *dlg);
};

void H2DTarget::SpawnModelessDialog(UIDialog *dlg) {
    if (m_mdiTarget != 0) {
        m_mdiTarget->SpawnModelessDialog(dlg);
    }
}
