struct AptString {
    char pad[0x0C];
    char m_string[1];

    char* GetInternalString();
};

char* AptString::GetInternalString() {
    return m_string;
}
