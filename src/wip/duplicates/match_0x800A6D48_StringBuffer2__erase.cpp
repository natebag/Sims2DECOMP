/* StringBuffer2::erase(void) at 0x800A6D48 (16B) */

struct StringBuffer2 {
    unsigned short* m_buffer;

    void erase(void);
};

void StringBuffer2::erase(void) {
    m_buffer[0] = 0;
}
