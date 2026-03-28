// 0x802C693C (8 bytes)
class EFile {
public:
    int GetExt();
};

int EFile::GetExt() {
    return (int)((char*)this + 0x24);
}
