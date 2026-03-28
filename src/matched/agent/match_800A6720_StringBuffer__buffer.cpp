// 0x800A6720 (8 bytes)
class StringBuffer {
public:
    char *m_buffer;

    char *buffer(void);
};

char *StringBuffer::buffer(void) {
    return m_buffer;
}
