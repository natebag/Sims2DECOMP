struct EFixedString_Init_S {
    char* m_buffer;
    int m_size;
    void Init(char*, int);
};

void EFixedString_Init_S::Init(char* buf, int size) {
    m_buffer = buf;
    m_size = size;
    buf[0] = 0;
}
