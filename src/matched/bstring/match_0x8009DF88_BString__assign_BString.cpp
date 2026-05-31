/* BString::assign(const BString&, unsigned int, unsigned int) - 0x8009DF88 (196 bytes) */

struct BStringRep {
    char *m_data;
    int m_length;
    int m_capacity;
    int m_refCount;
};

struct BString {
    BStringRep *m_rep;

    int length(void) const;
    char *data(void) const;
    int ref_count(void) const;
    void delete_ref(void);
    void assign_str(const char *s, unsigned int len);
    BString &assign(const BString &str, unsigned int pos, unsigned int n);
};

extern void basic_string_ref__throwrange(void);

BString &BString::assign(const BString &str, unsigned int pos, unsigned int n) {
    if (pos > (unsigned int)str.length())
        basic_string_ref__throwrange();

    unsigned int count;
    if (n > (unsigned int)(str.length() - pos))
        count = str.length() - pos;
    else
        count = n;

    if (count == (unsigned int)str.length() && str.ref_count() != -1) {
        delete_ref();
        m_rep = str.m_rep;
        ++m_rep->m_refCount;
    } else {
        assign_str(str.data() + pos, count);
    }
    return *this;
}
