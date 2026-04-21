// 0x801355D8 iResFile::~iResFile (76B)
// dtor: store vtable at +12; bl Unlink; delete-flag check.

extern int VT_iResFile[];

struct iResFile {
    char pad[12];
    int* m_vtable;
    void Unlink();
    ~iResFile();
};

iResFile::~iResFile() {
    m_vtable = VT_iResFile;
    Unlink();
}
