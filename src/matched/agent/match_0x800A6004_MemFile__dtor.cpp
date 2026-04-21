// 0x800A6004 MemFile::~MemFile (88B)
// dtor: vtable@+292; if (m_field276 != 0) Close(); delete-flag check.

extern int VT_MemFile[];

struct MemFile {
    char pad[276];
    int m_field276;
    char pad2[12];
    int* m_vtable;
    void Close();
    ~MemFile();
};

MemFile::~MemFile() {
    m_vtable = VT_MemFile;
    if (m_field276 != 0) Close();
}
