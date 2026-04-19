// 0x800226B8 (8B) EDummyFile::GetSystemHandle(void) const
// return 0 stub.

class EDummyFile {
public:
    int GetSystemHandle(void) const;
};

int EDummyFile::GetSystemHandle(void) const {
    return 0;
}
