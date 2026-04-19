// 0x801E6DF0 (64B) WXFTarget::onHelpDialogSelection(int)
// Counter increment with wrap-at-3: ++m_130; if (m_130 > 2) m_130 = 0; else ShowHelp().
// Store happens after cmp because SN schedules the cmplwi earlier.

class WXFTarget {
public:
    char pad_000[0x130];
    unsigned int m_field_130;

    void ShowHelp(void);
    void onHelpDialogSelection(int);
};

void WXFTarget::onHelpDialogSelection(int) {
    ++m_field_130;
    if (m_field_130 <= 2) {
        this->ShowHelp();
        return;
    }
    m_field_130 = 0;
}
