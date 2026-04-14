/* 0x800A3374 (84 bytes) - BString2::c_str(void) const */

struct BString2Rep {
    void *m_data;
};

struct BString2 {
    BString2Rep *m_rep;
    int length(void) const;
    void *c_str(void) const;
};

extern char BString2_empty[];

void *BString2::c_str(void) const {
    void *data = (length() == 0) ? 0 : m_rep->m_data;
    if (data)
        return data;
    return BString2_empty;
}
