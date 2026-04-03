// 0x80135624 (8 bytes)
class iResFile {
public:
    int GetError();
};

int iResFile::GetError() {
    return *(int*)((char*)this + 0x4);
}
