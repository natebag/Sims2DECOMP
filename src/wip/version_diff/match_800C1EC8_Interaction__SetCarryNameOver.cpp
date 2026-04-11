/* Interaction::SetCarryNameOver(bool) - 0x800C1EC8 (32 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    void SetCarryNameOver(bool val);
};

void Interaction::SetCarryNameOver(bool val) {
    m_flags &= ~64;
    if (val) {
        m_flags |= 64;
    }
}
