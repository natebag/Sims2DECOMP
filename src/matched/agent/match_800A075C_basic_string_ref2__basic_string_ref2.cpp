class basic_string_ref2 {
public:
    int pad_00;
    int pad_04;
    int pad_08;
    int m_refCount;

    basic_string_ref2(void);
};

basic_string_ref2::basic_string_ref2(void) {
    m_refCount = m_refCount + 1;
}
