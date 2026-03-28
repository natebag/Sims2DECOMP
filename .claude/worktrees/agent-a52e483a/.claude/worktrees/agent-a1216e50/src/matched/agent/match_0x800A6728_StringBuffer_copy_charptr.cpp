/* StringBuffer::copy(char *) - 0x800A6728 (64 bytes) */

struct StringBuffer {
    void erase();
    void append(char *, int);
    void copy(char *s);
};

void StringBuffer::copy(char *s)
{
    erase();
    append(s, -1);
}
