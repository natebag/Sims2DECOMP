// 0x802C6934 (8 bytes)
class EFile {
public:
    int GetName();
};

int EFile::GetName() {
    return *(int*)((char*)this + 0x20);
}
