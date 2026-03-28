class SomeBase2 {
public:
    int dummy;
};

void StartActionMenuImpl(SomeBase2*, void*, int);

class INVTarget {
public:
    char pad0[0x84];
    int m_actionMenuId;
    char pad1[0x3114];
    SomeBase2 m_base;
    void StartActionMenu(void);
};

void INVTarget::StartActionMenu(void) {
    StartActionMenuImpl(&m_base, this, m_actionMenuId);
}
