// 0x800A6E68 (8 bytes)
class StringBuffer2 {
public:
    char *m_buffer;

    char *c_str(void) const;
};

char *StringBuffer2::c_str(void) const {
    return m_buffer;
}
