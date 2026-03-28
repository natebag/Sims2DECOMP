// 0x802D8080 (8 bytes)
class ENgcSNFile {
public:
    int Tell();
};

int ENgcSNFile::Tell() {
    return *(int*)((char*)this + 0x30);
}
