// 0x800226A8 (8 bytes) — li r3, 1; blr

class EDummyFile {
public:
    int Flush();
};

int EDummyFile::Flush() {
    return 1;
}
