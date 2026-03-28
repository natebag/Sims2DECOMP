// 0x800226B8 (8 bytes) — li r3, 0; blr

class EDummyFile {
public:
    int GetSystemHandle() const;
};

int EDummyFile::GetSystemHandle() const {
    return 0;
}
