/* StringBuffer::erase(void) at 0x800A6610 (16B) */

struct StringBuffer {
    char* m_buffer;

    void erase(void);
};

void StringBuffer::erase(void) {
    m_buffer[0] = 0;
}
