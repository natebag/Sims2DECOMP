// 0x800A6D1C (8 bytes)
class StringBuffer2 {
public:
    void *m_buffer;
    int m_capacity;

    int capacity(void) const;
};

int StringBuffer2::capacity(void) const {
    return m_capacity;
}
