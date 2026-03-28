/* Interaction::GetCarryNameOver(void) const - 0x800C1EBC (12 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    int GetCarryNameOver(void) const;
};

int Interaction::GetCarryNameOver(void) const {
    return (m_flags >> 6) & 1;
}
