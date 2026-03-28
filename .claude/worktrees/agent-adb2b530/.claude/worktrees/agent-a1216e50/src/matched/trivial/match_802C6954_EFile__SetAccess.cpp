// 0x802C6954 (8 bytes)
class EFile {
public:
    void SetAccess(int p);
};

void EFile::SetAccess(int p) {
    *(int*)((char*)this + 0xC) = p;
}
