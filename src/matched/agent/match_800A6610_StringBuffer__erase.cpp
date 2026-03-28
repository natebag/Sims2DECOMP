class StringBuffer {
public:
    char *m_buffer;

    void erase(void);
};

void StringBuffer::erase(void) {
    m_buffer[0] = 0;
}
