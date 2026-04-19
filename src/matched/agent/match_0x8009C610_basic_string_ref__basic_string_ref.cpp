/* basic_string_ref::basic_string_ref(void) at 0x8009C610 (20B) */

struct basic_string_ref_ctor {
    char m_pad[12];
    int m_refCount;
    basic_string_ref_ctor();
};

basic_string_ref_ctor::basic_string_ref_ctor() {
    m_refCount++;
}
