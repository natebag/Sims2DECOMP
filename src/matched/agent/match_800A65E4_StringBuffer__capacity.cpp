// 0x800A65E4 (8 bytes)
class StringBuffer {
public:
    void *m_buffer;
    int m_capacity;

    int capacity(void) const;
};

int StringBuffer::capacity(void) const {
    return m_capacity;
}
