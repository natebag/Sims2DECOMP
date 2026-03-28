// 0x802C694C (8 bytes)
class EFile {
public:
    void SetDevice(int p);
};

void EFile::SetDevice(int p) {
    *(int*)((char*)this + 0x10) = p;
}
