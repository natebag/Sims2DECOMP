struct AptArray {
    char pad[0x2C];
    int m_length;

    int length();
};

int AptArray::length() {
    return m_length;
}
