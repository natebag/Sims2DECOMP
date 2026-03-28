// 0x800A6718 (8 bytes)
class StringBuffer {
public:
    char *m_buffer;

    char *c_str(void) const;
};

char *StringBuffer::c_str(void) const {
    return m_buffer;
}
