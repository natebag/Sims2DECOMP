// 0x802C692C (8 bytes)
class EFile {
public:
    int GetPath();
};

int EFile::GetPath() {
    return *(int*)((char*)this + 0x1C);
}
