/* ReconBuffer::PadBits(void) - 0x801332C4 - 12 bytes */
/* li r0, 0; stw r0, 0x28(r3); blr */

class ReconBuffer {
public:
    char _pad[0x28];
    int m_bitPosition;

    void PadBits(void);
};

void ReconBuffer::PadBits(void) {
    m_bitPosition = 0;
}
