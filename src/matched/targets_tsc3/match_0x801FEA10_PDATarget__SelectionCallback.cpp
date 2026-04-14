/* PDATarget::SelectionCallback(int) at 0x801FEA10 (144b) */

extern int UIDB_UIDBGetInt(const char *key);
extern const char gPDASelStr0[];
extern const char gPDASelStr1[];

struct PDATarget {
    char pad_00[0x170];
    int m_selectionPending;
    int m_selectionIndex;

    void SelectionCallback(int sel);
    void HandleButtonHelpMessage(int idx, int val);
};

void PDATarget::SelectionCallback(int sel) {
    if (m_selectionPending == 0) return;
    if (m_selectionIndex == 0) {
        m_selectionPending = m_selectionIndex;
        int val = UIDB_UIDBGetInt(gPDASelStr0);
        HandleButtonHelpMessage(0, val);
        return;
    }
    if (m_selectionIndex == 1) {
        m_selectionPending = 0;
        int val = UIDB_UIDBGetInt(gPDASelStr1);
        HandleButtonHelpMessage(1, val);
    }
}
