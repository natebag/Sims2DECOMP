// 0x800226B0 (8 bytes) — li r3, 0; blr

class EDummyFile {
public:
    int GetLastError() const;
};

int EDummyFile::GetLastError() const {
    return 0;
}
