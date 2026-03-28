/* 0x800A67A8 (68 bytes) - StringBuffer::append(StringBuffer &, int) */

class StringBuffer {
public:
    char *c_str(void) const;
    void append(char *str, int len);
    void append(StringBuffer &sb, int len);
};

void StringBuffer::append(StringBuffer &sb, int len)
{
    char *s = sb.c_str();
    append(s, len);
}
