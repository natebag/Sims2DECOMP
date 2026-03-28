// 0x802C6944 (8 bytes)
class EFile {
public:
    int GetLength();
};

int EFile::GetLength() {
    return *(int*)((char*)this + 0x14);
}
