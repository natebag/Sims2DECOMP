struct basic_string_ref {
    char pad[0x0C];
    int m_refCount;

    basic_string_ref(void);
};

basic_string_ref::basic_string_ref(void) {
    m_refCount = m_refCount + 1;
}
