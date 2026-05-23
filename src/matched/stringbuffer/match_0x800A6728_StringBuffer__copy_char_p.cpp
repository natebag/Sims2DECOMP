/* 0x800A6728 (64 bytes) - StringBuffer::copy(char *) */

class StringBuffer {
public:
    void erase(void);
    void append(char *str, int len);
    void copy(char *str);
};

void StringBuffer::copy(char *str)
{
    erase();
    append(str, -1);
}
