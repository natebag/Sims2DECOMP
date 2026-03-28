// 0x802C695C (8 bytes)
class EFile {
public:
    void SetMode(int p);
};

void EFile::SetMode(int p) {
    *(int*)((char*)this + 0x8) = p;
}
