struct AptString {
    char pad[0x10];
    AptString* m_next;

    AptString* GetNext() const;
};

AptString* AptString::GetNext() const {
    return m_next;
}
