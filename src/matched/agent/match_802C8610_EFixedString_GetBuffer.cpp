struct EFixedString_GB {
    char* m_buffer;
    int m_size;
    char* GetBuffer(int len);
};

char* EFixedString_GB::GetBuffer(int len) {
    if (len >= m_size) {
        return 0;
    }
    return m_buffer;
}
