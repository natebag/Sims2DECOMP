// 0x800226A0 (8 bytes)
class EDummyFile {
public:
    int Tell();
};

int EDummyFile::Tell() {
    return *(int*)((char*)this + 0x2C);
}
