/* StringBuffer::buffer(void) at 0x800A6720 (8B) */

struct StringBuffer {
    char* m_buffer;

    char* buffer(void);
};

char* StringBuffer::buffer(void) {
    return m_buffer;
}
