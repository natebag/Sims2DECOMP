class StringBuffer2 {
public:
    unsigned short *m_buffer;

    void erase(void);
};

void StringBuffer2::erase(void) {
    m_buffer[0] = 0;
}
