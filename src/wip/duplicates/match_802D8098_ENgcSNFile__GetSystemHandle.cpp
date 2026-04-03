// 0x802D8098 (8 bytes)
class ENgcSNFile {
public:
    int GetSystemHandle();
};

int ENgcSNFile::GetSystemHandle() {
    return *(int*)((char*)this + 0x2C);
}
