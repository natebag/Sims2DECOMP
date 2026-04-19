// 0x800226A8 (8B) EDummyFile::Flush(void)
// return 1 stub.

class EDummyFile {
public:
    int Flush(void);
};

int EDummyFile::Flush(void) {
    return 1;
}
