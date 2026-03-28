/* M2MTarget::UpdateSelection(int) at 0x801C294C (120B) */

struct M2MTarget {
    char pad_000[0x188];
    int m_numItems;
    int m_selection;

    void UpdateSelection(int direction);
    void ReflowButtonSelection();
};

void M2MTarget::UpdateSelection(int direction) {
    int oldSel = m_selection;
    if (direction < 0) {
        int newSel = m_selection - 1;
        m_selection = newSel;
        if (newSel < 0) {
            m_selection = m_numItems - 1;
        }
    } else if (direction > 0) {
        int newSel = m_selection + 1;
        m_selection = newSel;
        if (newSel >= m_numItems) {
            m_selection = 0;
        }
    }
    if (oldSel != m_selection) {
        ReflowButtonSelection();
    }
}
