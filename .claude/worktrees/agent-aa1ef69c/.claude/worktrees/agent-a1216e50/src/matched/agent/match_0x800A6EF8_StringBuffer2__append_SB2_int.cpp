/* 0x800A6EF8 (68 bytes) - StringBuffer2::append(StringBuffer2 &, int) */

typedef unsigned short wchar_t_ea;

class StringBuffer2 {
public:
    wchar_t_ea *c_str(void) const;
    void append(wchar_t_ea *str, int len);
    void append(StringBuffer2 &sb, int len);
};

void StringBuffer2::append(StringBuffer2 &sb, int len)
{
    wchar_t_ea *s = sb.c_str();
    append(s, len);
}
