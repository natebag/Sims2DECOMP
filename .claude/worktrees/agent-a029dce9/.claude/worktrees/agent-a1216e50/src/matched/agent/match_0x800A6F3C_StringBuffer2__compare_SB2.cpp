/* 0x800A6F3C (68 bytes) - StringBuffer2::compare(StringBuffer2 &) const */

typedef unsigned short wchar_t_ea;

int wcscmp(const wchar_t_ea *, const wchar_t_ea *);

class StringBuffer2 {
public:
    wchar_t_ea *c_str(void) const;
    int compare(StringBuffer2 &other) const;
};

int StringBuffer2::compare(StringBuffer2 &other) const
{
    wchar_t_ea *a = c_str();
    wchar_t_ea *b = other.c_str();
    return wcscmp(a, b);
}
