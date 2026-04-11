/* iResFile::Link(void) at 0x8013553C (16B) */

extern struct iResFile* g_resFileList;

struct iResFile {
    iResFile* m_next;

    void Link(void);
};

void iResFile::Link(void) {
    m_next = g_resFileList;
    g_resFileList = this;
}
