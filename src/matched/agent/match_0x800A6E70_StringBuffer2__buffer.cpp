/* StringBuffer2::buffer(void) at 0x800A6E70 (8B) */

struct StringBuffer2 {
    unsigned short* m_buffer;

    unsigned short* buffer(void);
};

unsigned short* StringBuffer2::buffer(void) {
    return m_buffer;
}
