/* 0x800A6EB8 (64 bytes) - StringBuffer2::copy(StringBuffer2 &) */

class StringBuffer2 {
public:
    void erase(void);
    void append(StringBuffer2 &sb, int len);
    void copy(StringBuffer2 &sb);
};

void StringBuffer2::copy(StringBuffer2 &sb)
{
    erase();
    append(sb, -1);
}
