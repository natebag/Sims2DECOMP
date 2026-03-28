/* Interaction::SetChecked(bool) - 0x800C1E18 (32 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    void SetChecked(bool val);
};

void Interaction::SetChecked(bool val) {
    m_flags &= ~4;
    if (val) {
        m_flags |= 4;
    }
}
