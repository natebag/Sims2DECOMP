// 0x802C6914 (8 bytes)
class EFile {
public:
    int GetAccessMode();
};

int EFile::GetAccessMode() {
    return *(int*)((char*)this + 0xC);
}
