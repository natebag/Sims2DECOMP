struct AptString {
    char pad[0x10];
    AptString* m_next;

    void SetNext(AptString* next);
};

void AptString::SetNext(AptString* next) {
    m_next = next;
}
