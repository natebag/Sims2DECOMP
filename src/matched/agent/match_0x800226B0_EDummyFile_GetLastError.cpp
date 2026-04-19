// 0x800226B0 (8B) EDummyFile::GetLastError(void) const
// return 0 stub.

class EDummyFile {
public:
    int GetLastError(void) const;
};

int EDummyFile::GetLastError(void) const {
    return 0;
}
