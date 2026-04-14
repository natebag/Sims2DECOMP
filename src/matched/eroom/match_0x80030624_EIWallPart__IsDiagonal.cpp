/* EIWallPart::IsDiagonal(void) - 0x80030624 (24 bytes) */

struct EIWallPart {
    char pad[0x320];
    int m_segment;

    int IsDiagonal();
};

int EIWallPart::IsDiagonal() {
    if (m_segment & 0x30) {
        return 1;
    }
    return 0;
}
