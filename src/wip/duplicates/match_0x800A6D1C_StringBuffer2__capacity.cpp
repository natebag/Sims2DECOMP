/* StringBuffer2::capacity(void) const at 0x800A6D1C (8B) */

struct StringBuffer2 {
    unsigned short* m_buffer;
    int m_capacity;

    int capacity(void) const;
};

int StringBuffer2::capacity(void) const {
    return m_capacity;
}
