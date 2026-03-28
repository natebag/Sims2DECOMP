// 0x802E1BF4 (8 bytes)
class ENgcFile {
public:
    int GetSystemHandle();
};

int ENgcFile::GetSystemHandle() {
    return (int)((char*)this + 0x2C);
}
