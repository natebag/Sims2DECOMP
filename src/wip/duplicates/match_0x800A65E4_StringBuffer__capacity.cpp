/* StringBuffer::capacity(void) const at 0x800A65E4 (8B) */

struct StringBuffer {
    char* m_buffer;
    int m_capacity;

    int capacity(void) const;
};

int StringBuffer::capacity(void) const {
    return m_capacity;
}
