/* 0x800A6E78 (64 bytes) - StringBuffer2::copy(unsigned wchar_t *) */

typedef unsigned short wchar_t_ea;

class StringBuffer2 {
public:
    void erase(void);
    void append(wchar_t_ea *str, int len);
    void copy(wchar_t_ea *str);
};

void StringBuffer2::copy(wchar_t_ea *str)
{
    erase();
    append(str, -1);
}
