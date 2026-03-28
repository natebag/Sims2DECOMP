class UIDialog;

void *operator new(unsigned int size);

class ITBTarget {
public:
    char _data[0xA0];

    ITBTarget();
    void SpawnIntroThoughtBalloon(UIDialog *dlg);
};

class H2DTarget {
public:
    char _pad[0xC4];
    ITBTarget *m_itbTarget;

    void SpawnIntroThoughtBalloon(UIDialog *dlg);
};

void H2DTarget::SpawnIntroThoughtBalloon(UIDialog *dlg) {
    if (m_itbTarget == 0) {
        m_itbTarget = new ITBTarget();
    }
    m_itbTarget->SpawnIntroThoughtBalloon(dlg);
}
