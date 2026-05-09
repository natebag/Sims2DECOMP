// BitMatrix64::BitMatrix64(void) - 0x8009BA54 (76 bytes)
// Default ctor: auto-constructs m_rows[64] array of BitArray64 (each 8 bytes).

class BitArray64 {
public:
    unsigned int m_lo;
    unsigned int m_hi;
    BitArray64();
};

class BitMatrix64 {
public:
    BitArray64 m_rows[64];
    BitMatrix64();
};

BitMatrix64::BitMatrix64()
{
}
