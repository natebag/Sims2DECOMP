// 0x800C1DE0 Interaction::GetContinuation (12B) — bit 0 of field@60
struct Interaction {
    char pad[60];
    int m_flags;
    int GetContinuation() const;
};
int Interaction::GetContinuation() const { return (m_flags >> 1) & 1; }
