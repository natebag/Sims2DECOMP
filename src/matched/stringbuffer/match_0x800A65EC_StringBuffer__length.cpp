// 0x800A65EC StringBuffer::length(void) const (36B)

extern int strlen(const char*);

struct StringBuffer {
    char* m_buffer;
    int length() const;
};

int StringBuffer::length() const {
    return strlen(m_buffer);
}
