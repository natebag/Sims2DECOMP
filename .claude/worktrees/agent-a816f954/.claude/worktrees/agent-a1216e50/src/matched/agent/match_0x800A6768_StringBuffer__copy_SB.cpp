/* 0x800A6768 (64 bytes) - StringBuffer::copy(StringBuffer &) */

class StringBuffer {
public:
    void erase(void);
    void append(StringBuffer &sb, int len);
    void copy(StringBuffer &sb);
};

void StringBuffer::copy(StringBuffer &sb)
{
    erase();
    append(sb, -1);
}
