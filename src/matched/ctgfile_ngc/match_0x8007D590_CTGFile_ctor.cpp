// 0x8007D590 CTGFile::CTGFile (20b)

extern int CTGFile_vtable[];

struct CTGFile {
    int* m_vt;
    CTGFile();
};

CTGFile::CTGFile() {
    *(int**)this = CTGFile_vtable;
}
