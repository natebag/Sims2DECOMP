// 0x800A6E70 (8 bytes)
class StringBuffer2 {
public:
    char *m_buffer;

    char *buffer(void);
};

char *StringBuffer2::buffer(void) {
    return m_buffer;
}
