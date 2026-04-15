/* 0x80133A98 ReconBuffer::ReadToNextMark(void) (76B) */

class ReconBuffer {
public:
    char pad0[8];
    int m_field_8;           // +0x08
    int m_field_C;           // +0x0C
    char pad1[8];
    int m_compressionEnabled; // +0x18
    char pad2[16];
    int m_field_2C;          // +0x2C

    void PadBits(void);
    void ReadToNextMark(void);
};

void ReconBuffer::ReadToNextMark(void) {
    if (m_compressionEnabled != 0) {
        PadBits();
    }
    if (m_field_C == 0) {
        m_field_8 = m_field_2C;
    }
}
