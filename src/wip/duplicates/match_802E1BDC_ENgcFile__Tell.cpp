// 0x802E1BDC (8 bytes)
class ENgcFile {
public:
    int Tell();
};

int ENgcFile::Tell() {
    return *(int*)((char*)this + 0x68);
}
